/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ss;
        toStringStream(ss, root);
        return ss.str();
    }
    
    void toStringStream(ostringstream& ss, TreeNode* r) {
        if (!r)
            ss << "# ";
        else {
            ss << r->val << " "; 
            toStringStream(ss, r->left);
            toStringStream(ss, r->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return fromStringStream(ss);
    }
    
    TreeNode* fromStringStream(istringstream& ss) {
        if (!ss)
            return NULL;
        
        string d;
        ss >> d;
        if (d[0] == '#')
            return NULL;
        
        TreeNode* r = new TreeNode(stoi(d));
        r->left = fromStringStream(ss);
        r->right = fromStringStream(ss);
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
