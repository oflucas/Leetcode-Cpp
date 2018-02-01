ass Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& g, int k) {
        if (g.empty())
            return INT_MIN;
        int n = g.size(), m = g[0].size();
        int ans = INT_MIN;
        for (int l = 0; l < m; l++) {
            vector<int> sums(n, 0);
            for (int r = l; r < m; r++) {
                for (int i = 0, sum = 0; i < n; i++) {
                    sum += g[i][r];
                    sums[i] += sum;
                }
                ans = max(ans, maxSumSubarray(sums, k));
            }
        }
        return ans;
    }
    
    int maxSumSubarray(const vector<int>& sums, int k) {
        int ans = INT_MIN;
        set<int> set_;
        set_.insert(0);
        for (auto sum : sums) {
            auto iter = set_.upper_bound(sum - k - 1);
            if (iter != set_.end())
                ans = max(ans, sum - *iter);
            set_.insert(sum);
        }
        return ans;
    }
};
