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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( head == NULL ) return head;
        
        int len(1);
        ListNode *curr = head;
        while ( curr->next != NULL )
        {
            curr = curr->next;
            ++len;
        }
        
        curr->next = head;
        int breakAt = len - k % len;
        curr = head;
        for ( int i = 0; i < breakAt - 1; ++i )
        {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   return 0;
}
