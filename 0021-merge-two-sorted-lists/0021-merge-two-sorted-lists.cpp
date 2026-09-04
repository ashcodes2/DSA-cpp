class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l1 != NULL && l2 != NULL) {

            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        // Bachi hui lisy attach
        if(l1 != NULL)
            curr->next = l1;
        else
            curr->next = l2;

        return dummy->next;
    }
};