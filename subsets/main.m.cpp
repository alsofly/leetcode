#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, const vector<vector<int> > vec)
{
   os << '[' << '\n';
   for ( int i = 0, len = vec.size(); i < len; ++i )
   {
      os << '[';
      vector<int> curr = vec[i];
      for ( int j = 0, currLen = curr.size(); j < currLen; ++j )
      {
         os << curr[j] << ", ";
      }
      os << "], \n";
   }
   os << ']' << '\n';
   return os;
}

class Solution {
public:
   vector<vector<int> > subsets(vector<int> &S) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      sort(S.begin(), S.end());
      vector<vector<int> > out;
      vector<int> curr;

      subsets(out, curr, 0, S);
      return out;

   }

   void subsets(
         vector<vector<int> >& out, 
         vector<int> curr, 
         int n, 
         const vector<int>& S)
   {
      int len = S.size();
      if ( n == len ) 
      {
         out.push_back(curr);
         return;
      }

      subsets(out, curr, n+1, S);
      curr.push_back(S[n]);
      subsets(out, curr, n+1, S);
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int intSet[] = {1,2,3};
   vector<int> intVec(intSet, intSet + sizeof(intSet)/sizeof(int));
   cout << sol.subsets(intVec) << endl;
   
   return 0;
}
