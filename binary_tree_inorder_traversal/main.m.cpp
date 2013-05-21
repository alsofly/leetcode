#include <iostream>
#include <vector>

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
      // Recursive in-order traversal
      
      vector<int> rtn;
      if ( root == NULL ) return rtn;

      inorderTraversal(rtn, root);
      return rtn;
   }

   void inorderTraversal(vector<int>& rtn, TreeNode *root) {
      if ( root->left != NULL ) inorderTraversal(rtn, root->left);
      rtn.push_back(root->val);
      if ( root->right != NULL ) inorderTraversal(rtn, root->right);
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;

   
   return 0;
}
