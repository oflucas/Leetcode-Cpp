class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> size_map;
        int ans = 0;
        for (auto i : nums)
            if (GetKey(size_map, i, 0) == 0) {
                int dright = GetKey(size_map, i + 1, 0);
                int dleft = GetKey(size_map, i - 1, 0);
                size_map[i + dright] = 1 + dright + dleft;
                size_map[i - dleft] = 1 + dright + dleft;
                size_map[i] = 1 + dright + dleft;
                ans = max(ans, 1 + dright + dleft);
            }
        
        return ans;
    }
    
    int GetKey(const unordered_map<int, int>& h, int key, int default_val) {
        auto iter = h.find(key);
        return iter == h.end() ? default_val : iter->second;
    }
};
