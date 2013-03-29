/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int sum = l1->val + l2->val;
        int digit = sum % 10;
        int adv = sum/10;
        ListNode *head = new ListNode(digit);
        ListNode *curr = head;
        ListNode *next = NULL;
        
        if ( l1 != NULL ) l1 = l1->next; 
        if ( l2 != NULL ) l2 = l2->next;
        while ( l1 != NULL || l2 != NULL )
        {
            sum = (l1 != NULL ? l1->val : 0)
                + (l2 != NULL ? l2->val : 0) + adv;
            digit = sum % 10;
            adv = sum/10;
            next = new ListNode(digit);
            curr->next = next;
            curr = next;
            
            if ( l1 != NULL ) l1 = l1->next;
            if ( l2 != NULL ) l2 = l2->next;
        }
        
        if ( adv > 0 )
        {
            curr->next = new ListNode(adv);
        }
        
        return head;
    }
};
