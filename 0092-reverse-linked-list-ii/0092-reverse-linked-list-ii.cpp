class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        ListNode *p = pre, *q = pre->next;
        ListNode* cur = q;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        p->next = pre;
        q->next = cur;
        return dummy->next;
    }
};