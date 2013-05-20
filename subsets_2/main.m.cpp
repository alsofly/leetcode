#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, const vector<vector<int> > vec)
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
   vector<vector<int> > subsetsWithDup(vector<int> &S) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      sort(S.begin(), S.end());
      vector<vector<int> > out;
      vector<int> curr;
      subsetsWithDump(out, S, 0, curr); 

      return out;
   }

   void subsetsWithDump(
         vector<vector<int> >& out, 
         const vector<int>& S,
         int pos,
         vector<int> curr)
   {
      if ( pos == S.size() ) 
      {
         out.push_back(curr);
         return;
      }

      vector<int>::const_iterator upperIter = upper_bound(S.begin()+pos, S.end(), S[pos]);
      int upper(upperIter - S.begin());
      subsetsWithDump(out, S, upper, curr);
      for ( int i = 0; i < upper - pos; ++i )
      {
         curr.push_back(S[pos]);
         subsetsWithDump(out, S, upper, curr);
      }
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int vec[] = {1, 2, 2, 4};
   vector<int> intVec(vec, vec + sizeof(vec)/sizeof(int));
   cout << sol.subsetsWithDup(intVec) << endl;
   return 0;
}
