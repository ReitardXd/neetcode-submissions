class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode* joined = head;
        ListNode* sublist = head->next;

        joined->next = nullptr;

        while (sublist) {
            // Find the last node of sublist
            ListNode* prev = nullptr;
            ListNode* curr = sublist;

            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }

            // curr is the last node
            // Remove curr from sublist
            if (prev) {
                prev->next = nullptr;
            } else {
                // sublist had only one node
                sublist = nullptr;
            }

            // Append curr to joined
            curr->next = nullptr;
            joined->next = curr;
            joined = curr;

 
            if (sublist) {
                ListNode* first = sublist;
                sublist = sublist->next;

                first->next = nullptr;
                joined->next = first;
                joined = first;
            }
        }
    }
};
