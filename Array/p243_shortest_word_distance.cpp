class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i = -1, j = -1, minD = words.size();
        for (int k = 0; k < words.size(); k++) {
            if (words[k] == word1)
                i = k;
            else
            if (words[k] == word2)
                j = k;
                
            if (i >=0 && j >= 0 && abs(i - j) < minD)
                minD = abs(i - j);
        }
        return minD;
    }
};
