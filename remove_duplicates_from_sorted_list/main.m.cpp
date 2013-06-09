#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *curr = head;
        while ( curr != NULL )
        {
            ListNode *repeat = curr;
            while ( repeat != NULL 
                 && repeat->next != NULL
                 && repeat->val == repeat->next->val )
            {
                repeat = repeat->next;         
            }
            curr->next = repeat->next;
            curr = repeat->next;
        }
        return head;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
