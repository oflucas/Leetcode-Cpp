/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand(time(NULL));
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int k = 0, res = 0;
        for (ListNode* i = head; i; i = i->next) {
            if (rand() % ++k == 0)
                res = i->val;
        }
        return res;
    }

private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
