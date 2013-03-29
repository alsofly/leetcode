/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total(0);
        int currSum(0);
        vector<TreeNode *> stack;
        stack.push_back(root);
        
        traverse(root, stack, currSum, total);
        return total;
    }
    
    void traverse(TreeNode *node, 
                  vector<TreeNode *>& stack,
                  int& currSum, 
                  int& total)
    {   
        if ( NULL == node )
        {
            stack.pop_back();
            return;
        }
        
        currSum = currSum*10 + node->val;
        if ( NULL == node->left && NULL == node->right )
        {
            total += currSum;
            currSum /= 10;
            stack.pop_back();
            return;
        }
        
        TreeNode *currNode = node->left;
        stack.push_back(currNode);
        traverse(currNode, stack, currSum, total);
        
        currNode = node->right;
        stack.push_back(currNode);
        traverse(currNode, stack, currSum, total);
        
        currSum /= 10;
        stack.pop_back();
    }
    
    
};