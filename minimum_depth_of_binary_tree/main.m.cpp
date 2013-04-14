/**
 * Definition for binary tree
 */
#include <iostream>

using namespace std;


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( NULL == root ) return 0;
        
        if ( NULL == root->left && NULL == root->right )
        {
            return 1;
        }
        
        if ( NULL == root->left )
        {
            return minDepth(root->right) + 1;
        }
        
        if ( NULL == root->right )
        {
            return minDepth(root->left) + 1;
        }
        
        return min(minDepth(root->left), minDepth(root->right)) + 1;
            
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   return 0;
}
