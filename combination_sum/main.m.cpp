#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<vector<int> >& vec)
{
   os << "[\n";
   for ( int i = 0, len = vec.size(); i < len; ++i )
   {
      os << '[';
      const vector<int>& curr = vec[i]; 
      for ( int j = 0, currLen = curr.size(); j < currLen; ++j )
      {
         os << curr[j] << ", ";
      }
      os << "],\n";
   }
   os << "]\n";
   return os;
}


class Solution {
public:
   vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      vector<vector<int> > rtn;
      return rtn;
   }
};

int main(int argc, const char *argv[])
{
   int a[] = {2,3,6,7};
   vector<int> b(a, a+sizeof(a)/sizeof(int));
   Solution sol;
   cout << sol.combinationSum(b, 7) << endl;   
   return 0;
}
