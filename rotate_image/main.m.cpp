#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = matrix.size();
        for ( int i = len; i > 1; i -= 2 )
        {
            int y = (len - i)/2; 
            for ( int x = y; x < i + y - 1; ++x )
            {
                int temp(matrix[x][y]);
                matrix[x][y] = matrix[len-1-y][x];
                matrix[len-1-y][x] = matrix[len-1-x][len-1-y];
                matrix[len-1-x][len-1-y] = matrix[y][len-1-x];
                matrix[y][len-1-x] = temp;
            }
        }
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
