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
ListNode *partition(ListNode *head, int x) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   ListNode *sHead(NULL), *sCurr(NULL), *bHead(NULL), *bCurr(NULL);
   ListNode *curr(head);
   while ( curr != NULL )
   {
      if ( curr->val < x )
      {
         if ( sHead == NULL )
         {
            sHead = curr;
            sCurr = sHead;
         }
         else
         {
            sCurr->next = curr;
            sCurr = curr;
         }
      }
      else
      {
         if ( bHead == NULL )
         {
            bHead = curr;
            bCurr = bHead;
         }
         else
         {
            bCurr->next = curr;
            bCurr = curr;
         }
      }
      curr = curr->next;
   }
   
   if ( sHead != NULL )
   {
      sCurr->next = bHead;
   }
   else
   {
      sHead = bHead;
   }

   if ( bHead != NULL )
   {
      bCurr->next = NULL;
   }

   return sHead;
}
};


int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
