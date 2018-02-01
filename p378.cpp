class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        while (l < r) {
            int mid = l + (r - l) / 2;
            int size_ = countSmallerOrEq(matrix, mid);
            if (size_ < k)
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
    
    int countSmallerOrEq(vector<vector<int>>& a, int v) {
        int n = a.size();
        int count = 0;
        for (int i = n - 1, j = 0; i >= 0 && j < n;) {
            if (a[i][j] <= v) {
                count += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return count;
    }
};
