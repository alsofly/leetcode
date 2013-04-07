#include <iostream>
#include <vector>
#include <numeric>

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rtn;
        vector<pair<TreeNode *, int> > nodeStack;
        vector<int> stack;
        TreeNode *node = root;
        int level = 0;
        
        while ( nodeStack.size() > 0 || NULL != node )
        {
            if ( NULL != node )
            {
                stack.push_back(node->val);
                nodeStack.push_back(pair<TreeNode *, int>(node->right, ++level));
                
                if ( node->left == NULL && node->right == NULL )
                {
                    if ( sum == accumulate(stack.begin(), stack.end(), 0) )
                    {
                        rtn.push_back(stack);
                    }
                }
                
                node = node->left;
            }
            else
            {
                pair<TreeNode *, int> last = nodeStack.back();
                for ( int i = stack.size(); i > last.second; --i )
                {
                    stack.pop_back();
                }
                level = last.second;
                node  = last.first;
                nodeStack.pop_back();
            }
        }
    
        return rtn;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
