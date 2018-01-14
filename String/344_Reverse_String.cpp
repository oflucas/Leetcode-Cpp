// Total Accepted: 80334
// Total Submissions: 137711
// Difficulty: Easy
// 0ms 100%

class Solution {
public:
    string reverseString(string s) {
        for(int i = 0, j = s.length() - 1; i < j; swap(s[i++], s[j--]));
        return s;
    }
};