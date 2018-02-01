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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dmyHead = new ListNode(0), *i, *j;
        dmyHead->next = head;
        n -= m;
        for (i = dmyHead; m > 1; m--)
            i = i->next;
        j = i->next;
        
        for (; n > 0; n--) {
            ListNode* q = j->next;
            j->next = q->next;
            q->next = i->next;
            i->next = q;
        }
        
        i = dmyHead->next;
        delete dmyHead;
        return i;
    }
};
