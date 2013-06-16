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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int first = find_smallest(lists);
        if ( first == -1 ) return NULL;
        
        ListNode *head = lists[first];
        ListNode *curr = head;
        while ( true )
        {
            lists[first] = lists[first]->next;
            first = find_smallest(lists);
            if ( first == -1 )
            {
                curr->next = NULL;
                break;
            }
            curr->next = lists[first];
            curr = curr->next;
        }
        
        
        return head;
    }
    
    int find_smallest(vector<ListNode *>& lists)
    {
        int rtn(-1);
        for ( int i = 0; i < lists.size(); ++i )
        {
            if ( lists[i] == NULL ) continue;
            if ( rtn == -1 )
            {
                rtn = i;
            }
            else if ( lists[i]->val < lists[rtn]->val )
            {
                rtn = i;
            }
        }
        return rtn;
    }
};

int main()
{
   Solution sol;
   
   return 0;
}





