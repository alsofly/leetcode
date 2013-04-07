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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( root == NULL ) return;
        traverse(root);
        
    }
    
    TreeNode * traverse(TreeNode *root)
    {
        TreeNode *right = root->right;
        TreeNode *leftLast = NULL;
        if ( NULL != root->left )
        {
            root->right = root->left;
            leftLast = traverse(root->left);
            root->left = NULL;
            leftLast->right = right;
        }
        
        if ( NULL != right )
        {
            return traverse(right);
        }
        else
        {
            return leftLast == NULL ? root : leftLast;    
        }
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
