#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
ostream& operator<< (ostream& os, const vector<vector<T> > strVecVec)
{
   for ( int i = 0; i < strVecVec.size(); ++i )
   {
      os << "[";
      vector<T> strVec = strVecVec[i];
      for ( int j = 0; j < strVec.size(); ++j )
      {
         os << strVec[j] << (j == strVec.size() - 1 ? "" : ",");
      }
      os << "]" << endl;
   }
   return os;
}

class Solution {
public:
vector<vector<int> > fourSum(vector<int> &num, int target) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   vector<vector<int> > rtn;        
   if ( num.size() < 4 ) return rtn;

   sort(num.begin(), num.end());
   vector<int> curr;
   vector<int>::const_iterator it = num.begin();
   fourSumImpl(rtn, num, it, curr, 0, target);

   return rtn;
}

void fourSumImpl(
      vector<vector<int> >& rtn,
      const vector<int>& num,
      vector<int>::const_iterator& it,
      vector<int>& curr,
      const int sum,
      const int target)
{
   if ( curr.size() == 4 )
   {
      if ( sum == target ) rtn.push_back(curr);
      return;
   }

   if ( curr.size() == 3 && sum + *num.rbegin() < target ) return;
   if ( curr.size() == 2 && sum + *num.rbegin() + *(num.rbegin() + 1) < target ) return;

   for ( vector<int>::const_iterator iit = it; iit != num.end(); ++iit )
   {
      vector<int> tmpl = curr;
      if ( iit - it > 0 && *(iit - 1) == *iit ) continue;

      tmpl.push_back(*iit);
      vector<int>::const_iterator iiit = iit + 1;
      fourSumImpl(rtn, num, iiit, tmpl, sum + *iit, target);
   }
}
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int target = -11;
   int h[] = {1,-2,-5,-4,-3,3,3,5};
   vector<int> height(h, h+sizeof(h)/sizeof(int));
   cout << sol.fourSum(height, target) << endl;
   
   return 0;
}
