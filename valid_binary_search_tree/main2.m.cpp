#include <iostream>
#include <limits>

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
       if ( root == NULL ) return true;
       if ( root->val <= lower || root->val >= upper ) return false;
       if ( false == isValidBST(root->left, lower, root->val) ) return false;
       if ( false == isValidBST(root->right, root->val, upper) ) return false;
       return true;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
