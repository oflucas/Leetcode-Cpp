class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> cur;
        dfs(0, used, nums, cur, ans);
        return ans;
    }
    
    void dfs(int depth, vector<bool> used, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        if (depth == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = 0, last = -1; i < nums.size(); i++)
            if (!used[i] && (last < 0 || nums[i] != nums[last])) {
                cur.push_back(nums[i]);
                used[i] = true;
                dfs(depth + 1, used, nums, cur, ans);
                last = i;
                cur.pop_back();
                used[i] = false;
            }
    }
};
