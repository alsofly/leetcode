#include <iostream>
#include <output.h>

using namespace std;

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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( head == NULL ) return NULL;
        if ( head->next == NULL ) return head;
        
        ListNode *pre = NULL;
        ListNode *first = head;
        ListNode *second = first->next;
        head = second;
        while ( first != NULL && second != NULL )
        {
            ListNode *next = second->next;
            if ( pre != NULL ) pre->next = second;
            second->next = first;
            first->next = next;
            pre = first;
            first = next;
            if ( first != NULL ) second = first->next;
        }
        
        return head;
    }
};

int main()
{
   Solution sol;
   int a[] = {8,4,9,1,5,8,3,6,1};
   vector<int> arr(a, a+sizeof(a)/sizeof(int));
   ListNode *head = create_linkedList_from_array(arr);
   cout << head << endl;
   cout << sol.swapPairs(head) << endl;
   return 0;
}
