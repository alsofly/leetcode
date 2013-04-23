#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (  NULL == root ) return;
        vector<TreeLinkNode *> currLevel;
        currLevel.push_back(root);
        
        while ( currLevel.size() > 0 )
        {
            vector<TreeLinkNode *> nextLevel;
            for ( int i = 0, size = currLevel.size();
                  i < size; ++i )
            {
                TreeLinkNode *node = currLevel[i];
                if ( NULL != node->left ) nextLevel.push_back(node->left);
                if ( NULL != node->right ) nextLevel.push_back(node->right);
                if ( i < size - 1 ) node->next = currLevel[i+1];
            }
            currLevel = nextLevel;
        }
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;

   
   return 0;
}
