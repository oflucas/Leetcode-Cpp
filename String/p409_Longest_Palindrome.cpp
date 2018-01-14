class Solution {
public:
    int longestPalindrome(string s) {
        long flag = 0;
        int odd = 0;
        for (auto ch : s)
            flag ^= long(1) << ch - 'A';
        
        for (int i = 0; i <= 'z' - 'A'; i++)
            odd += (flag >> i) & 1;

        return s.length() - max(odd - 1, 0);
    }
};
