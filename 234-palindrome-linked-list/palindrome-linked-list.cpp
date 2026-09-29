class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* prev = NULL;

        while (slow != NULL) {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // 3. Compare both halves
        while (prev != NULL) {
            if (head->val != prev->val) {
                return false;
            }

            head = head->next;
            prev = prev->next;
        }

        return true;
    }
};