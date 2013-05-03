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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 1;
        ListNode *beforeStart = NULL;
        ListNode *start = head;
        while ( i < m )
        {
            beforeStart = start;
            start = start->next;
            ++i;
        }
        
        ListNode *end = start;
        ListNode *afterEnd = end->next;
        while ( i < n )
        {
            ListNode *next(NULL);
            if ( afterEnd != NULL ) next = afterEnd->next;
            afterEnd->next = end;
            end = afterEnd;
            afterEnd = next;
            ++i;
        }
        
        start->next = afterEnd;
        if ( beforeStart != NULL ) 
        {
            beforeStart->next = end;
            return head;
        }
        else
        {
            return end;
        }       
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
