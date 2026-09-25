class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);   // we are creating sum like 0->8->0->7
        ListNode* current = dummy;

        int carry = 0;

        while (l1 || l2 || carry) {

            int x = (l1) ? l1->val : 0;
            int y = (l2) ? l2->val : 0;

            int sum = x + y + carry;

            carry = sum / 10;

            //current ke next me new node banao then right most digit add kar do 
            current->next = new ListNode(sum % 10);   

            current = current->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;    // if return dummy only then it will 0807 which is wrong
    }
};