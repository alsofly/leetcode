#include <iostream>
#include <vector>
#include <string>

using namespace std;

ostream& operator<<(ostream& os, const vector<string>& input)
{
   os << "[";
   for ( vector<string>::const_iterator it = input.begin();
         it != input.end(); ++it )
   {
      os << *it << ", ";
   }
   os << "]";
   return os;
}

class Solution {
public:
struct compClass {
   bool operator() (const string& a, const string& b)
   {
      return a.size() < b.size();
   }
} compObject;

string longestCommonPrefix(vector<string> &strs) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   if ( strs.size() == 0 ) return "";

   sort(strs.begin(), strs.end(), compObject);
   cout << strs << endl;

   int p = strs[0].size();
   for ( int i = 1, len = strs.size(); i < len && p > 0; ++i )
   {
      cout << p << endl;
      string& curr = strs[i];
      int j = 0;
      for ( ; j < p && curr[j] == strs[0][j]; ++j );
      p = j;
   }
   return strs[0].substr(0, p);
}
};

int main(int argc, const char *argv[])
{
   vector<string> input;
   input.push_back("flower");
   input.push_back("flow");
   input.push_back("flighted");

   Solution sol;
   cout << sol.longestCommonPrefix(input) << endl;
   
   return 0;
}
