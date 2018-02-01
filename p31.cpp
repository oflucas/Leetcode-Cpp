class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
            return;
        int p = nums.size() - 1;
        for (; p > 0 && nums[p - 1] >= nums[p]; p--);
        reverse(&nums[p], &nums.back());
        if (p <= 0)
            return;
        
        for (int i = p; i < nums.size(); i++) {
            if (nums[i] > nums[p - 1]) {
                swap(&nums[p - 1], &nums[i]);
                break;
            }
        }
    }
    
private:
    void reverse(int* l, int* r) {
        while (l < r)
            swap(l++, r--);
    }
    
    void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
};
