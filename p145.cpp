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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return vector<int>();
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        for (TreeNode *p = st.top(), *prev = NULL; !st.empty();) {
            p = st.top();
            if (p->left && (!prev || prev->left == p || prev->right == p)) {
                st.push(p->left);
            } else if (p->right && p->right != prev) {
                st.push(p->right);
            } else {
                res.push_back(p->val);
                st.pop();
            }
            prev = p;
        }
        return res;
    }
};
