#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function

      int len = obstacleGrid.size();
      int width = obstacleGrid[0].size();
      for ( int i = 0; i < len; ++i )
      {
         for ( int j = 0; j < width; ++j )
         {
            int& curr = obstacleGrid[i][j];
            if ( curr == 1 )
            {
               curr = 0;
            }
            else if ( i == 0 && j == 0 ) 
            {
               curr = 1;
            }
            else if ( i == 0 )
            {

               curr = obstacleGrid[0][j-1];
            }
            else if ( j == 0 )
            {

               curr = obstacleGrid[i-1][0];
            }
            else
            {
               curr = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
         }
      }

      return obstacleGrid[len-1][width-1];
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
