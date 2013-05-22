#include <iostream>

using namespace std;

class Solution {
public:
   int romanToInt(string s) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function

      int sum(0), pre(0), curr(0);
      for ( int i = 0; i < s.size(); ++i )
      {
         pre = curr;
         curr = number(s[i]);
         sum += curr;
         if ( curr > pre ) 
         {
            sum -= 2 * pre;
         }
      }
      return sum;
   }

   int number(const char c)
   {
      switch ( c )
      {
         case 'I': return 1;
         case 'V': return 5;
         case 'X': return 10;
         case 'L': return 50;
         case 'C': return 100;
         case 'D': return 500;
         case 'M': return 1000;
      }
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.romanToInt("VIII") << endl;
   return 0;
}
