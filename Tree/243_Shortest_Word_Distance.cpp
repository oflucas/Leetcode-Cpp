// Total Accepted: 15774
// Total Submissions: 32372
// Difficulty: Easy
// 16ms 100%

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i1 = -1,  i2 = -1, ans = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (word1 == words[i])
                i1 = i;
            else
            if (word2 == words[i])
                i2 = i;
            
            if (i1 >= 0 && i2 >= 0)
                ans = min(ans, abs(i1 - i2));
        }
        return ans;
    }
};