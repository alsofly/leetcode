#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   bool searchMatrix(vector<vector<int> > &matrix, int target) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      int row = matrix.size();
      int col = matrix[0].size();
      int head(0), tail(row-1);
      if ( target >= matrix[tail][0] ) head = row - 1;
      else{
         int mid = (head + tail)/2;
         while ( mid > head )
         {
            if ( target < matrix[mid][0] ) tail = mid;
            else head = mid;
            mid = (head + tail)/2;
         }
      }

      int rowHead(0), rowTail(col-1);
      if ( target == matrix[head][rowTail] ) return true;
      int rowMid = (rowHead + rowTail)/2;
      while ( rowMid > rowHead )
      {
         if ( target == matrix[head][rowMid] ) return true;
         if ( target > matrix[head][rowMid] ) rowHead = rowMid;
         else rowTail = rowMid;
         rowMid = (rowHead + rowTail)/2;
      }
      return target == matrix[head][rowHead];
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;

   
   return 0;
}
