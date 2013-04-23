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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( NULL == root ) return true;
        vector<TreeNode *> currLevel;
        currLevel.push_back(root);
        
        while ( currLevel.size() > 0 )
        {
            vector<TreeNode *> nextLevel;
            int i(0), size(currLevel.size());
            for ( ; i <= size - 1 - i; ++i )
            {
                TreeNode *leftNode = currLevel[i];
                TreeNode *rightNode = currLevel[size - 1 - i];
                if ( leftNode->val != rightNode->val ) return false;
                
                if ( (leftNode->left == NULL) != (rightNode->right == NULL) ) 
                {
                    return false;      
                }
                else if ( leftNode->left != NULL && rightNode->right != NULL )
                {
                    nextLevel.push_back(leftNode->left);
                }
                
                if ( (leftNode->right == NULL) != (rightNode->left == NULL) )
                {
                    return false;
                }
                else if ( leftNode->right != NULL && rightNode->left != NULL )
                {
                    nextLevel.push_back(leftNode->right);
                }
            }
            
            for ( ; i < size; ++i )
            {
                TreeNode *node = currLevel[i];
                if ( node->left != NULL ) nextLevel.push_back(node->left);
                if ( node->right != NULL ) nextLevel.push_back(node->right);
            }
            currLevel = nextLevel;
        }
        
        return true;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
