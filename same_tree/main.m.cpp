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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( p == NULL && q == NULL ) return true;
        if ( p == NULL && q != NULL || p != NULL && q == NULL ) return false;
        if ( p->val != q->val ) return false;
        if ( false == isSameTree(p->left, q->left) ) return false;
        if ( false == isSameTree(p->right, q->right) ) return false;
        
        return true;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
