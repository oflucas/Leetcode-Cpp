class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        dfs(0, nums, cur, ans);
        return ans;
    }
    
    void dfs(int pos, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        if (cur.size() > 1)
            ans.push_back(cur);
        
        unordered_set<int> set_;
        for (int i = pos; i < nums.size(); i++)
            if ((cur.empty() || cur.back() <= nums[i]) && !set_.count(nums[i])) {
                cur.push_back(nums[i]);
                dfs(i + 1, nums, cur, ans);
                cur.pop_back();
                set_.insert(nums[i]);
            }
    }
};
