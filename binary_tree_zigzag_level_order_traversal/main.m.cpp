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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rtn;
        vector<TreeNode *> currLevel;
        
        if ( NULL == root ) return rtn;
        currLevel.push_back(root);
        bool left2right(true);
        
        while ( currLevel.size() > 0 )
        {
            vector<TreeNode *> nextLevel;
            vector<int> currRtn(currLevel.size());
            for ( int size = currLevel.size(), i = size - 1; i >= 0; --i )
            {
                currRtn[i] = currLevel[i]->val;
                if ( left2right )
                {
                    if ( currLevel[i]->right != NULL ) nextLevel.push_back(currLevel[i]->right);
                    if ( currLevel[i]->left != NULL ) nextLevel.push_back(currLevel[i]->left);            
                }
                else
                {
                    if ( currLevel[i]->left != NULL ) nextLevel.push_back(currLevel[i]->left);
                    if ( currLevel[i]->right != NULL ) nextLevel.push_back(currLevel[i]->right);
                }
            }
            rtn.push_back(currRtn);
            currLevel = nextLevel;
            left2right = !left2right;
        }
        return rtn;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
