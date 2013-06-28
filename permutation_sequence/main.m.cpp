#include <iostream>
#include <sstream>
#include <output.h>

using namespace std;

class Solution {
public:
string getPermutation(int n, int k) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   int i(n-1), div(1);
   while ( i > 0 ) div *= i--;

   vector<int> allNum;
   for ( int i = 0; i < n; ++i ) allNum.push_back(i + 1);

   i = n - 1;
   k--;
   ostringstream oss;
   while ( i > 0 )
   {
      int sn = k / div;
      k = k % div;
      div /= i--;
      oss << allNum[sn];
      allNum.erase(allNum.begin() + sn);
   }
   oss << allNum[0];
   
   return oss.str();
}
};

int main()
{
   Solution sol;
   cout << sol.getPermutation(4, 10) << endl;
   return 0;
}

