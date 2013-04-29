#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> uniqueTree;
        uniqueTree[0] = 1;
        
        for ( int i = 1; i <= n; ++i )
        {
            int unique(0);
            for ( int j = 0; j < i; ++j )
            {
                unique += uniqueTree[j] * uniqueTree[i - 1 - j];
            }
            uniqueTree[i] = unique;
        }
        
        return uniqueTree[n];
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.numTrees(8) << endl;
   
   return 0;
}
