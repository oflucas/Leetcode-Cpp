// Total Accepted: 149962
// Total Submissions: 290920
// Difficulty: Easy
// 16ms 100%

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i : nums) res ^= i;
        return res;
    }
};