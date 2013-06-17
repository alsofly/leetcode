#include <iostream>
#include <vector>
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newHead(NULL), *next(NULL);
        if ( !reverseKGroup(head, k, &newHead, &next) )
        {
            return head;
        }
        
        ListNode *hPre(next), *hAfter(NULL), *preTail(head);
        while ( reverseKGroup(hPre, k, &hAfter, &next) )
        {
            preTail->next = hAfter;
            preTail = hPre;
            hPre = next;
        }
        preTail->next = hPre;
            
        return newHead;
    }
    
    bool reverseKGroup(
            ListNode *hPre,
            int k,
            ListNode **hAfter,
            ListNode **next)
    {
        ListNode *curr = hPre;
        int count(0);
        while ( count++ < k )
        {
            if ( curr == NULL ) return false;
            curr = curr->next;
        }
        
        ListNode *head = hPre;
        *hAfter = hPre;
        *next = hPre->next;
        count = 0;
        while ( ++count < k )
        {
            *hAfter = *next;
            *next = (*next)->next;
            (*hAfter)->next = head;
            head = *hAfter;
        }
        return true;
    }
};

int test(int k)
{
   Solution sol;
   int a[] = {6,3,4,8,9,2,8,2,7};
   vector<int> arr(a, a + sizeof(a)/sizeof(int));
   ListNode *head = create_linkedList_from_array(arr);
   cout << "k = " << k << " - " << head << endl;
   cout << sol.reverseKGroup(head, k) << endl;
   cout << endl;
}

int main()
{
   test(1);
   test(2);
   test(3);
   test(4);
   test(5);
   test(8);
   test(10);
   return 0;
}
