
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;
        
        // Phase 1: Detect the cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        
        // If no cycle exists, return null
        if (!hasCycle) {
            return nullptr;
        }
        
        // Phase 2: Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow; // Both pointers now point to the start of the cycle
    }
};