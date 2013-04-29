#include <iostream>

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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBST(TreeNode *root, int lower, int upper)
    {
        if ( NULL == root ) return true;
        
        if ( root->left != NULL )
        {
            int upperLeft = min(upper, root->val);
            if ( root->left->val >= upperLeft || root->left->val <= lower )
            {
                return false;
            }
            
            if ( isValidBST(root->left, lower, upperLeft) == false ) 
            {
                return false;
            }
        }
        
        if ( root->right != NULL )
        {
            int lowerRight = max(lower, root->val);
            if ( root->right->val <= lowerRight || root->right->val >= upper )
            {
                return false;
            }
            
            if ( isValidBST(root->right, lowerRight, upper) == false )
            {
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
