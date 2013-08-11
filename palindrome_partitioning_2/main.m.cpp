#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
      int minCut(string s)
      {

         return 0;
      }

      vector<vector<string> > partition(string s) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function

         vector<vector<string> > rtnVec;
         for ( int i = s.size(); i > 0; --i )
         {
            // Start from longest possbility, decide if it is palindrome
            string subStr = s.substr(0, i);
            if ( is_palindrome(subStr) ) {
               if ( s.size() - i  == 0 )
               {
                  vector<string> temp;
                  temp.push_back(subStr);
                  rtnVec.push_back(temp);
                  continue;
               }
               vector<vector<string> > restPart = 
                  partition(s.substr(i, s.size() - i));
               for ( int j = 0; j < restPart.size(); ++j ) {
                  vector<string> combined;
                  combined.reserve(1 + restPart[j].size());
                  combined.push_back(subStr);
                  combined.insert(combined.end(), 
                        restPart[j].begin(),
                        restPart[j].end() );
                  rtnVec.push_back(combined);
               }                
            }
         }

         return rtnVec;
      }

      // Decide if it is palindrome
      bool is_palindrome(const string& s) {
         int size = s.size();
         int halfSize = size/2;
         for ( int i = 0; i < halfSize; ++i )
         {
            if ( s[i] != s[size - i - 1] ) return false;
         }
         return true;
      }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   string ts(argv[1]);
   std::cout << sol.minCut(ts) << std::endl;

   return 0;
}
