class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) {
            return nullptr;
        }

        return divide(lists, 0, lists.size() - 1);
    }

private:

    ListNode* divide(vector<ListNode*>& lists, int l, int r) {

        // No lists
        if (l > r) {
            return nullptr;
        }

        // Only one list
        if (l == r) {
            return lists[l];
        }

        // Find middle
        int mid = l + (r - l) / 2;

        // Divide
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid + 1, r);

        // Conquer / merge
        return conquer(left, right);
    }

    ListNode* conquer(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 && l2) {

            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        // Attach whatever is left
        if (l1) {
            curr->next = l1;
        }
        else {
            curr->next = l2;
        }

        return dummy.next;
    }
};