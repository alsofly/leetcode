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
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function

   return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

TreeNode *buildTree(
      vector<int>& preorder,
      int preHead,
      int preTail,
      vector<int>& inorder,
      int inHead,
      int inTail)
{
   if ( inTail - inHead == 0 ) return NULL;

   int headVal = preorder[preHead];
   TreeNode *head = new TreeNode(headVal);

   int rightFirst = find(inorder.begin()+inHead, inorder.begin()+inTail, headVal) - inorder.begin(); 
   head->left  = buildTree(preorder, preHead+1                  , preHead +1 + rightFirst - inHead, 
                           inorder , inHead                     , rightFirst);
   head->right = buildTree(preorder, preHead+rightFirst+1-inHead, preTail, 
                           inorder , rightFirst+1               , inTail);

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
   int pre[] = {1, 2, 3, 4};
   vector<int> preorder(pre, pre+sizeof(pre)/sizeof(int));
   int in[] = {1, 2, 3, 4};
   vector<int> inorder(in, in+sizeof(in)/sizeof(int));
   cout << sol.buildTree(preorder, inorder) << endl;
   return 0;
}
