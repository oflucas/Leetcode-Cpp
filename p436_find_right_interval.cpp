# include <iostream>
# include <vector>

using namespace std;

/**
 *  * Definition for an interval.
 *         */
 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        return vector<int>(10, 1);      
    }
};


int main(int argc, char * argv[]) {
    vector<Interval> intervals{{1, 2}, {3, 4}};
    for (const auto& i : intervals)
        cout << "("<< i.start << ", " << i.end << ")";
    
    Solution sol;
    auto res = sol.findRightInterval(intervals);
    
    for (const auto& i : res)
        cout << i << ", ";

    cout << endl;
    
    return 0;
}
