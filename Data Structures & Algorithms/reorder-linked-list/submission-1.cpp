class Solution {
public:
    void reorderList(ListNode* head) {

        // Empty list or single-node list
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split the list
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 3. Reverse the second half
        ListNode* prev = nullptr;

        while (second != nullptr) {
            ListNode* tmp = second->next;

            second->next = prev;
            prev = second;
            second = tmp;
        }

        // 4. Merge the two halves
        ListNode* first = head;
        second = prev;

        while (second != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
