#ifndef INCLUDED_OUTPUT
#define INCLUDED_OUTPUT

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <functional>

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<std::vector<T> >& strVecVec)
{
   os << "[\n";
   for ( size_t i = 0; i < strVecVec.size(); ++i )
   {
      os << "  [";
      std::vector<T> strVec = strVecVec[i];
      for ( size_t j = 0; j < strVec.size(); ++j )
      {
         os << strVec[j] << (j == strVec.size() - 1 ? "" : ",");
      }
      os << "]\n";
   }
   os << "]";
   return os;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& strVec)
{
   os << "[";
   for ( size_t j = 0; j < strVec.size(); ++j )
   {
      os << strVec[j] << (j == strVec.size() - 1 ? "" : ",");
   }
   os << "]";
   return os;
}

template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const std::multimap<T, S, std::greater<T> >& input)
{
   os << "[";
   for ( typename std::multimap<T,S>::const_iterator it = input.begin(), itE = input.end();
         it != itE; ++it )
   {
      os << it->first << "->" << it->second << ", ";
   }
   os << "]";
   return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& input)
{
   os << "[";
   for ( typename std::set<T>::const_iterator it = input.begin(), itE = input.end();
         it != itE; ++it )
   {
      os << *it << ", ";
   }
   os << "]";
   return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T, std::greater<T> >& input)
{
   os << "[";
   for ( typename std::set<T>::const_iterator it = input.begin(), itE = input.end();
         it != itE; ++it )
   {
      os << *it << ", ";
   }
   os << "]";
   return os;
}

/**
 * Definition for singly-linked list.
 */
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

std::ostream& operator<<(std::ostream& os, ListNode *head)
{
   os << "[";
   while ( head != NULL )
   {
      bool hasNext = head->next != NULL;
      os << head->val << (hasNext ? "," : "");
      head = head->next;
   }
   os << "]";
   return os;
}

ListNode *create_linkedList_from_array(const std::vector<int>& vec)
{
   ListNode *head = NULL;
   if ( vec.size() == 0 ) return head;
   else
   {
      head = new ListNode(vec[0]);
   }
   ListNode *curr = head;
   for ( std::vector<int>::const_iterator it = vec.begin() + 1
         , itE = vec.end(); it != itE; ++it )
   {
      ListNode *currNext = new ListNode(*it);
      curr->next = currNext;
      curr = currNext;
   }
   return head;
}


/**
 * Definition for binary tree
 */
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#endif
