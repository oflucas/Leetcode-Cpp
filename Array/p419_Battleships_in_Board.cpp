class Solution {
public:
    int countBattleships(vector<vector<char>>& b) {
        int n = b.size(), m = b[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (b[i][j] == 'X') {
                    if (j == 0 || b[i][j - 1] != 'X')
                        if (i == 0 || b[i - 1][j] != 'X')
                            ans++;
                }
        return ans;       
    }
};
