#include <iostream>
#include <output.h>

/**
 * Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 */
using namespace std;

class Solution {
public:
ListNode *deleteDuplicates(ListNode *head) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   head = next(head);
   if ( head == NULL ) return NULL;

   ListNode *curr = head;
   ListNode *currNext;
   while ( curr != NULL )
   {
      currNext = next(curr->next);
      curr->next = currNext;
      curr = currNext;
   }

   return head;
}

// return hext node which doesn't have duplicates starting from head
ListNode *next(ListNode *head) {
   while ( true ) {
      if ( head == NULL ) return NULL;
      bool changeHead(false);
      while ( head->next != NULL && head->val == head->next->val )
      {
         head = head->next;
         changeHead = true;
      }
      if ( changeHead )
      {
         head = head->next;
      }
      else
      {
         return head;
      }
   }
}
};

int main()
{
   Solution sol;
   int v[] = {1,2,3,3,4,4,5};
   vector<int> vec(v, v+sizeof(v)/sizeof(int));
   ListNode *head = create_linkedList_from_array(vec);
   cout << head << endl;
   cout << sol.deleteDuplicates(head) << endl;

   return 0;
}
