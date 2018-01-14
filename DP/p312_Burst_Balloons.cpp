class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        a.push_back(1);
        for (int i : nums) a.push_back(i);
        a.push_back(1);
        
        auto dp = new int*[n + 2];
        for (int i = 0; i < n + 2; dp[i++] = new int[n + 2]());
        
        for (int d = 3; d <= n + 2; d++)
            for (int i = 0, j = i + d - 1; j < n + 2; i++, j++) {
                int p = i + 1, tmp = dp[i][p] + a[i] * a[p] * a[j] + dp[p][j];
                for (p++; p < j; p++)
                    tmp = max(tmp, dp[i][p] + a[i] * a[p] * a[j] + dp[p][j]);
                dp[i][j] = tmp;
            }
        
        return dp[0][n + 1];            
    }
};
