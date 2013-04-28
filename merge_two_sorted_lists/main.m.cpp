#include <iostream>

using namespace std;

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head(NULL), *curr(NULL), *next1(l1), *next2(l2);
        if ( l1 == NULL ) return l2;
        if ( l2 == NULL ) return l1;
        
        if ( l1->val < l2->val )
        {
            head = l1;
            next1 = l1->next;
            next2 = l2;
        }
        else
        {
            head = l2;
            next2 = l2->next;
            next1 = l1;
        }
        curr = head;
        
        while ( next1 != NULL && next2 != NULL )
        {
            if ( next1->val < next2->val )
            {
                curr->next = next1;
                curr = next1;
                next1 = next1->next;
            }
            else
            {
                curr->next = next2;
                curr = next2;
                next2 = next2->next;
            }
        }
        
        curr->next = (next1 == NULL ? next2 : next1);
        
        return head;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   return 0;
}
