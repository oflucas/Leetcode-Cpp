// Total Accepted: 12746
// Total Submissions: 24728
// Difficulty: Easy
// 3ms 8%

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 1; i < s.length(); i++) 
            if (s[i] == '+' && s[i - 1] == '+') {
                s[i] = s[i - 1] = '-';
                ans.push_back(s);
                s[i] = s[i - 1] = '+';
            }
        return ans;
    }
};