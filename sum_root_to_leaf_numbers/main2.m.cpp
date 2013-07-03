#include <iostream>
#include <vector>
#include <output.h>

using namespace std;

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
    int sumNumbers(TreeNode *root) 
    {
        int total(0), currSum(0);
        vector<TreeNode *> stack;
        traverse(root, total, currSum, stack);
        return total;
    }
    
    void traverse(
        TreeNode *root, 
        int& total, 
        int& currSum,
        vector<TreeNode *>& stack)
    {
        if ( root == NULL ) return;

        stack.push_back(root);
        currSum = currSum * 10 + root->val;
        if ( root->left == NULL && root->right == NULL )
        {
           total += currSum;
        }
        traverse(root->left, total, currSum, stack);
        traverse(root->right, total, currSum, stack);
        stack.pop_back();
        currSum = (currSum - root->val)/10;
    }
};

int main()
{
   Solution sol;
   TreeNode *root = new TreeNode(1);
   TreeNode *left = new TreeNode(2);
   TreeNode *right = new TreeNode(3);
   root->left = left;
   root->right = right;
   cout << sol.sumNumbers(root) << endl;
   return 0;
}
