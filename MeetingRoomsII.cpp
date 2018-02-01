#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> Meeting;

class Solution {
public:
    vector<vector<Meeting>> ScheduleMeetings(vector<Meeting> meetings) {
        typedef vector<Meeting> Room;
        auto RoomCmp = [](const Room& a, const Room& b) {
            return a.back().second > b.back().second;
        };
        priority_queue<Room, vector<Room>, decltype(RoomCmp)> pq(RoomCmp);
        
        sort(meetings.begin(), meetings.end());
        for (const auto& meeting : meetings) {
            if (pq.empty() || pq.top().back().second > meeting.first) {
                pq.push(Room{meeting});
            } else {
                auto room = pq.top();
                pq.pop();
                room.push_back(meeting);
                pq.push(room);
            }
        }

        vector<Room> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;   
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<Meeting> meetings{{1, 5}, {10, 15}, {3, 13}, {4,8},{2,3},{6,7},{9, 12},{8, 16},{10,20},{1,8}};
    vector<vector<Meeting>> ans = sol.ScheduleMeetings(meetings);
    for (const auto& room : ans) {
        for (const auto& m : room)
            cout << m.first << "~" << m.second << " ";
        cout << "\n";
    }
    return 0;
}
