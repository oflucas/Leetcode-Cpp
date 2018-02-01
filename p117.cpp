/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* head = new TreeLinkNode(0);
        for (TreeLinkNode* p = GetNextParent(root); p; p = GetNextParent(head->next))           
            for (TreeLinkNode* i = head; p; p = GetNextParent(p->next)) {
                if (p->left) {
                    i->next = p->left;
                    i = i->next;
                }
                if (p->right) {
                    i->next = p->right;
                    i = i->next;
                }  
            }
        delete head;
    }
    
    TreeLinkNode* GetNextParent(TreeLinkNode* i) {
        for (; i && (!i->left && !i->right); i = i->next);
        return i;
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* head = new TreeLinkNode(0);
        head->next = root;
        while (head->next) {
            TreeLinkNode* prev = head;
            for (TreeLinkNode *i = head->next; i; i = i->next)
                if (i->left || i->right) {
                    if (i->left) {
                        prev->next = i->left;
                        prev = prev->next;
                    }
                    if (i->right) {
                        prev->next = i->right;
                        prev = prev->next;
                    }
                }
            prev->next = NULL;
        }
    }
};
