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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxSum = root->val;
        maxRoot2Descendent(root, maxSum);
        return maxSum;
    }
    
    // return the max sum of root->descendent
    int maxRoot2Descendent(TreeNode *root, int& maxSum)
    {
        int leftMax(0), rightMax(0);
        if ( root->left != NULL )
        {
            leftMax = maxRoot2Descendent(root->left, maxSum);
        }
        
        if ( root->right != NULL )
        {
            rightMax = maxRoot2Descendent(root->right, maxSum);
        }
        
        int maxIncludeRoot = root->val;
        if ( leftMax > 0 ) maxIncludeRoot += leftMax;
        if ( rightMax > 0 ) maxIncludeRoot += rightMax;
        maxSum = max(maxSum, maxIncludeRoot);
        return root->val + max(0, max(leftMax, rightMax)); 
    }
};

