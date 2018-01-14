class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        vector<int> tmp(nums);
        mergeSort(nums, tmp, 0, nums.size(), cnt);
        return cnt;
    }
    
    void mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r, int& cnt) {
        if (r - l < 2)
            return;
        
        int mid = (l + r + 1) / 2;
        mergeSort(nums, tmp, l, mid, cnt);
        mergeSort(nums, tmp, mid, r, cnt);
        cnt += calRp(nums, l, mid, r);
        
        for (int i = l, j = mid, k = 0; i < mid || j < r; ) {
            if (i >= mid)
                tmp[k++] = nums[j++];
            else
            if (j >= r)
                tmp[k++] = nums[i++];
            else
            if (nums[i] < nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }
        
        for (int i = l, k = 0; i < r; nums[i++] = tmp[k++]);
    }
    
    int calRp(vector<int>& nums, int l, int mid, int r) {
        int cnt = 0;
        for (int i = l, j = mid; i < mid; i++) {
            for (; j < r && isRp(nums[i], nums[j]); j++);
            cnt += j - mid;
        }
        return cnt;
    }
    
    bool isRp(long numi, long numj) {
        return numj * 2 < numi;
    }
};
