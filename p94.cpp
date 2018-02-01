/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        for (TreeNode* p = root; p; ) {
            if (!p->left) {
                res.push_back(p->val);
                p = p->right;
                continue;
            }
            
            TreeNode* r = p->left;
            while (r->right && r->right != p) {
                r = r->right;
            }
            
            if (!r->right) {
                r->right = p;
                p = p->left;
            } else if (r->right == p) {
                r->right = NULL;
                res.push_back(p->val);
                p = p->right;
            } else {
                cout << "Weird";
            }
        }
        return res;
    }
    
    vector<int> inorderTraversal_STACK(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        for (TreeNode* p = root; !st.empty() || p; ) {
            while (p && p->left) {
                st.push(p);
                p = p->left;
            }
            
            if (p == NULL) {
                p = st.top();
                st.pop();
            }
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};
