// Total Accepted: 16981
// Total Submissions: 32081
// Difficulty: Easy
// 0ms 100%

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[256], n_odd = 0;
        memset(cnt, 0, sizeof(cnt));
        for (char c : s) cnt[c]++;
        for (int i = 0; i < 256 && n_odd < 2; n_odd += cnt[i++] & 1);
        return n_odd < 2;
    }
};