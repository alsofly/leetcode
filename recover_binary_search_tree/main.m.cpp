#include <iostream>
#include <output.h>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void recoverTree(TreeNode *root) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   TreeNode *pre(NULL), *first(NULL), *second(NULL);
   traverse(root, pre, &first, &second);
   first->val = first->val ^ second->val;
   second->val = first->val ^ second->val;
   first->val = first->val ^ second->val;
}

TreeNode *traverse(TreeNode *root, 
      TreeNode *pre,
      TreeNode **first, 
      TreeNode **second)
{
   if ( root == NULL ) return pre;

   TreeNode *leftLast = traverse(root->left, pre, first, second);
   if ( leftLast != NULL && leftLast->val > root->val )
   {
      if ( *first == NULL ) 
      {
         *first = leftLast;
         *second = root;

      }
      else 
      {
         *second = root;
      }
   }

   return traverse(root->right, root, first, second);
}
};

int main()
{
   Solution sol;
   TreeNode root(0);
   TreeNode left(1);
   root.left = &left;
   cout << &root << endl;
   sol.recoverTree(&root);
   cout << &root << endl;

   return 0;
}
