#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function

   return buildTree(inorder, 0, inorder.size(), 
         postorder, 0, postorder.size());
}

TreeNode *buildTree(
      vector<int>& inorder,
      int inHead,
      int inTail,
      vector<int>& postorder,
      int postHead,
      int postTail)
{
   if ( inTail - inHead == 0 ) return NULL;

   int headVal = postorder[postTail-1];
   TreeNode *head = new TreeNode(headVal);

   int rightFirst = find(inorder.begin() + inHead,
         inorder.begin() + inTail, headVal) 
      - inorder.begin(); 
   head->left = buildTree(inorder, inHead, rightFirst,
         postorder, postHead, rightFirst-inHead+postHead);
   head->right = buildTree(inorder, rightFirst+1, inTail,
         postorder, rightFirst-inHead+postHead, postTail-1);

   return head;
}

};

ostream& operator<<(ostream& os, TreeNode *head)
{
   if ( NULL == head )
   {
      os << "#";
      return os;
   }

   queue<TreeNode *> que;
   os << head->val << ", ";
   que.push(head);
   while ( que.size() > 0 )
   {
      TreeNode *curr = que.front();
      que.pop();

      if ( curr->left != NULL )
      {
         que.push(curr->left);
         os << curr->left->val << ", ";
      }
      else
      {
         os << "#, ";
      }

      if ( curr->right != NULL )
      {
         que.push(curr->right);
         os << curr->right->val << ", ";
      }
      else
      {
         os << "#, ";
      }
   }
   return os;
}

int main(int argc, const char *argv[])
{
   Solution sol;
   int in[] = {1, 2, 3, 4};
   vector<int> inorder(in, in+sizeof(in)/sizeof(int));
   int post[] = {3, 2, 4, 1};
   vector<int> postorder(post, post+sizeof(post)/sizeof(int));
   cout << sol.buildTree(inorder, postorder) << endl;
   return 0;
}
