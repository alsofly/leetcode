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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( num.size() == 0 ) return NULL;
        return sort(num, 0, num.size() - 1);
    }
    
    TreeNode *sort(vector<int>& num, int head, int tail) {
        int middle = (head + tail)/2;
        TreeNode *node = new TreeNode(num[middle]);
        if ( middle > head ) node->left = sort(num, head, middle - 1);
        if ( middle < tail ) node->right = sort(num, middle + 1, tail);
        return node;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
