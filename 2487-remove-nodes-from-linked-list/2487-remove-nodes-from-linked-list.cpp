
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) return head;

      
        head = reverseList(head);

        ListNode* curr = head;
        int maxVal = curr->val;

        while (curr && curr->next) {
            if (curr->next->val < maxVal) {
            
                curr->next = curr->next->next;
            } else {
              
                maxVal = curr->next->val;
                curr = curr->next;
            }
        }

        // Step 3: Reverse back to restore the original relative order
        return reverseList(head);
    }
};