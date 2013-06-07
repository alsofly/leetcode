#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
string countAndSay(int n) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   string s("1");
   string t;
   for ( int i = 0; i < n - 1; ++i )
   {
      int j = 0; 
      while ( j < s.size() )
      {
         int count(1);
         while ( s[j+1] == s[j] && j != s.size() - 1 ) 
         {
            ++count;
            ++j;
         }
         t.push_back(count + '0');
         t.push_back(s[j]);
         ++j;
      }
      s = t;
      t.erase();
   }
   return s;
}
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.countAndSay(5) << endl;
   
   return 0;
}
