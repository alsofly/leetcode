#include <iostream>
#include <vector>
#include <output.h>

using namespace std;

class Solution {
public:
   vector<vector<int> > generateMatrix(int n) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      vector<vector<int> > rtn;
      rtn.resize(n, vector<int>(n, 1));

      int len(n), origin(0), firstNum(1);
      while ( len > 0 )
      {
         firstNum = paint_peri(rtn, origin, len, firstNum);
         ++origin;
         len -= 2;
      }

      return rtn;
   }

   // return the number next to the last number
   int paint_peri(
         vector<vector<int> >& matrix,
         int origin,
         int len,
         int firstNum)
   {
      if ( len == 1 ) 
      {
         matrix[origin][origin] = firstNum;
         return firstNum + 1;
      }

      for ( int i = 0; i < len - 1; ++i )
      {
         matrix[origin][origin+i] = firstNum + i;
         matrix[origin+i][origin+len-1] = firstNum + len - 1 +i;
         matrix[origin+len-1][origin+len-1-i] = firstNum + 2*(len-1) +i;
         matrix[origin+len-1-i][origin] = firstNum + 3*(len-1) +i;
      }

      return firstNum + 4*(len - 1);
   }

};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.generateMatrix(5) << endl;
   return 0;
}
