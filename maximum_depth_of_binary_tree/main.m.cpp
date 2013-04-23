#include <iostream>

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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( NULL == root ) return 0;
        
        if ( NULL == root->left && NULL == root->right )
        {
            return 1;
        }
        
        if ( NULL == root->left )
        {
            return maxDepth(root->right) + 1;
        }
        
        if ( NULL == root->right )
        {
            return maxDepth(root->left) + 1;
        }
        
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
