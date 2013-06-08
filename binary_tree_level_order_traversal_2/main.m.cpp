#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
vector<vector<int> > levelOrderBottom(TreeNode *root) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   vector<vector<int> > rtn;
   if ( root == NULL ) return rtn;

   queue<pair<TreeNode *, int> > que;
   que.push(make_pair(root, 0));
   vector<int> curr;
   int currLevel(0);
   while ( que.size() > 0 )
   {
      const pair<TreeNode *, int>& one = que.front();
      que.pop();
      if ( one.second != currLevel )
      {
         rtn.push_back(curr);
         curr.clear();
         currLevel += 1;
      }
      curr.push_back(one.first->val);

      if ( one.first->left != NULL ) 
         que.push(make_pair(one.first->left, currLevel+1));
      if ( one.first->right != NULL )
         que.push(make_pair(one.first->right, currLevel+1));           
   }
   rtn.push_back(curr);

   reverse(rtn.begin(), rtn.end());
   return rtn;
}
};

int main(int argc, const char *argv[])
{
   Solution sol;

   return 0;
}
