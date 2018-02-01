class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n < 1)
            return vector<int>();
        vector<int> count(n, 0);
        
        BSTNode* root = new BSTNode(nums[n - 1]);
        for (int i = n - 2; i >= 0; i--)
            count[i] = insert(root, nums[i]);
        return count;
    }
    
    struct BSTNode {
        int val;
        int left_count, dup_count;
        BSTNode *left, *right;
        
        BSTNode(int val): val(val), left_count(0), dup_count(1), left(NULL), right(NULL) {}
    };
    
    int insert(BSTNode* root, int num) {
        if (!root)
            return 0;
        
        int ans = 0;
        if (num > root->val) {
            ans += root->left_count + root->dup_count;
            ans += insert(root->right, num);
            if (!root->right)
                root->right = new BSTNode(num);
        } else if (num < root->val) {
            root->left_count++;
            ans += insert(root->left, num);
            if (!root->left)
                root->left = new BSTNode(num);
        } else {
            root->dup_count++;
            ans += root->left_count;
        }
        return ans;
    }
    
    vector<int> countSmaller_MERGE(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        vector<pair<int, int>> arr, dmy(nums.size());
        for (int i = 0; i < nums.size(); i++)
            arr.emplace_back(make_pair(nums[i], i));
        
        merge(0, arr.size() - 1, arr, count, dmy);
        return count;
    }
    
    void merge(int l, int r, vector<pair<int, int>>& arr, vector<int>& count, vector<pair<int, int>>& dmy) {
        if (l >= r)
            return;
        
        int mid = (l + r) / 2;
        merge(l, mid, arr, count, dmy);
        merge(mid + 1, r, arr, count, dmy);
        
        for (int i = l; i <= mid; i++) {
            int j = mid + 1;
            while (j <= r && arr[j].first < arr[i].first)
                j++;
            count[arr[i].second] += j - (mid + 1);
        }
        
        for (int k = l, i = l, j = mid + 1; k <= r; k++)
            if (i > mid)
                dmy[k] = arr[j++];
            else if (j > r)
                dmy[k] = arr[i++];
            else if (arr[i].first <= arr[j].first)
                dmy[k] = arr[i++];
            else
                dmy[k] = arr[j++];
        
        for (int k = l; k <= r; k++)
            arr[k] = dmy[k];
    }
};
