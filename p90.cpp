class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>());
        vector<int> cur;
        //dfs(0, cur, ans, nums);
        for (int i = 0, j = 0; i < nums.size(); i = j) {
            for (j = i; j < nums.size() && nums[j] == nums[i]; j++);
            int rep = j - i;
            for (int k = 0, m = ans.size(); k < m; k++) {
                vector<int> prev = ans[k];
                for (int r = 0; r < rep; r++) {
                    prev.push_back(nums[i]);
                    ans.push_back(prev);
                }
            }
        }
        return ans;
    }
    
    void dfs(int pos, vector<int>& cur, vector<vector<int>>& ans, const vector<int>& nums) {
        ans.push_back(cur);
        
        for (int i = pos; i < nums.size(); i++) {
            if (i > pos && nums[i] == nums[i - 1])
                continue;
            cur.push_back(nums[i]);
            dfs(i + 1, cur, ans, nums);
            cur.pop_back();            
        }
    }
};
