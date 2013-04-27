#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height = grid.size();
        int width = grid[0].size();
        
        for ( int i = height -1; i >= 0; --i )
        {
            for ( int j = width -1; j >= 0; --j )
            {
                if ( i == height - 1 && j == width - 1 ) continue;
                int nextDown  = i == height - 1 ? INT_MAX : grid[i+1][j];
                int nextRight = j == width  - 1 ? INT_MAX : grid[i][j+1];
                grid[i][j] += min(nextDown, nextRight);
            }
        }
        
        return grid[0][0];
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
