#include <iostream>
#include <vector>
#include <stack>

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
   vector<int> inorderTraversal(TreeNode *root) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      //
      // Interative way of in-order traversal

      vector<int> rtn;
      stack<TreeNode *> myStack;
      while ( myStack.size() > 0 || root != NULL )
      {
         if ( root != NULL )
         {
            myStack.push(root);
            root = root->left;
         }
         else
         {
            root = myStack.top();
            myStack.pop();
            rtn.push_back(root->val);
            root = root->right;
         }
      }
      
      return rtn;
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;

   
   return 0;
}
