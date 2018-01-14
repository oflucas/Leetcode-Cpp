#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Edge;

class Solution {
public:
    vector<int> MakeCourseSchedule(vector<Edge>& dependencies, int numCourse) {
        vector<bool> visited(numCourse, false), visiting(numCourse, false);
        vector<int> order;
    
        for (int i = 0; i < numCourse; i++)
            if (!dfs(i, visited, visiting, order, dependencies))
                return {};
    
        return order;
    }
    
    bool dfs(int i, vector<bool>& visited, vector<bool>& visiting, vector<int>& order, const vector<Edge>& dependencies) {
        if (visited[i])
            return true;
    
        if (visiting[i])
            return false;
    
        visiting[i] = true;
    
        for (const auto& e : dependencies)
            if (e.first == i)
                if (!dfs(e.second, visited, visiting, order, dependencies))
                    return false;
    
        order.push_back(i);
        visiting[i] = false;
        visited[i] = true;
        return true;
    };
};

int main() {
    vector<Edge> deps{{1,0},{2,0},{3,2}};
    int numCourse = 4;

    Solution sol;
    auto schedule = sol.MakeCourseSchedule(deps, numCourse);

    for (int c : schedule)
        cout << c << ", ";
    cout << "\n";
    
    return 0;
}
