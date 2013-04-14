#include <iostream>

using namespace std;


//  Definition for binary tree
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth(0);
        return isBalanced(root, depth); 
        
    }
    
    bool isBalanced(TreeNode *root, int& depth) {
        if ( NULL == root ) 
        {
            depth = 0;
            return true;
        }
        
        int depthLeft(0);
        if ( false == isBalanced(root->left, depthLeft) )
        {
            return false;
        }
        
        int depthRight(0);
        if ( false == isBalanced(root->right, depthRight) )
        {
            return false;
        }
        
        if ( abs(depthLeft - depthRight) > 1 )
        {
            return false;
        }
        
        depth = max(depthLeft, depthRight) + 1;
        return true;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;   
   
   return 0;
}
