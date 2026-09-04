class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Fast n steps aage
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // both moves
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Nth node delete
        slow->next = slow->next->next;

        return dummy->next;
    }
};