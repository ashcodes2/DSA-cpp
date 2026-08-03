class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int left = 0;
        int right = nodes.size() - 1;

        while (left < right) {
            nodes[left]->next = nodes[right];
            left++;

            if (left == right) break;

            nodes[right]->next = nodes[left];
            right--;
        }

        nodes[left]->next = nullptr;
    }
};