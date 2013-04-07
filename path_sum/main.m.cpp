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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( NULL == root ) return false;
        return hasPathSum(root, sum, 0); 
    }
    
    bool hasPathSum(TreeNode *root, const int sum, int preSum)
    {
        preSum += root->val;
        if ( NULL == root->left && NULL == root->right )
        {
            return sum == preSum;
        }
        
        if ( NULL != root->left )
        {
            if ( true == hasPathSum(root->left, sum, preSum) )
            {
                return true;
            }
        }
        
        if ( NULL != root->right )
        {
            return hasPathSum(root->right, sum, preSum);
        }
        
        return false;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
