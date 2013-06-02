#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

      vector<int>::iterator it = unique(candidates.begin(), candidates.end());
      candidates.resize(distance(candidates.begin(), it));
      sort(candidates.begin(), candidates.end());
      
      vector<int> curr;
      vector<int>::const_iterator iit = candidates.begin();
      combinationSumImpl(rtn, candidates, iit, curr, target); 

      return rtn;
   }

   void combinationSumImpl(
         vector<vector<int> >& rtn,
         const vector<int>& candidates,
         vector<int>::const_iterator& it,
         vector<int>& curr, 
         const int target)
   {
      int sum = accumulate(curr.begin(), curr.end(), 0);
      if ( sum == target )
      {
         rtn.push_back(curr);
         return;
      }
      if ( sum > target ) return;
      if ( it == candidates.end() ) return;

      for (vector<int>::const_iterator iit = it; iit != candidates.end(); ++iit )
      {
         vector<int> temp = curr;
         temp.push_back(*iit);
         combinationSumImpl(rtn, candidates, iit, temp, target); 
      }
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
