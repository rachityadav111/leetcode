class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Fast ko n steps aage le jao
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Dono ko saath move karo
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow ke next node ko delete karo
        slow->next = slow->next->next;

        return dummy->next;
    }
};