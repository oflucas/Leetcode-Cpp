/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Codec {
public:
    /* Encodes a tree to a single string. */
    string serialize(TreeNode* root) {
        ostringstream os;
        ser(os, root);
        return os.str();
    }

    /* Decodes your encoded data to tree. */
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deser(is);
    }
    
private:
    void ser(ostringstream& os, TreeNode* r) {
        if (r) {
            os << r->val << ' ';
            ser(os, r->left);
            ser(os, r->right);
        } else 
            os << "# ";
    }
    
    TreeNode* deser(istringstream& is) {
        if (!is)
            return nullptr;
        string val;
        is >> val;
        if (val == "#")
            return nullptr;
            
        TreeNode *r = new TreeNode(stoi(val));
        r->left = deser(is);
        r->right = deser(is);
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// // Codec codec;
// // codec.deserialize(codec.serialize(root));
