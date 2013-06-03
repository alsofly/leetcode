#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
vector<vector<int> > threeSum(vector<int> &num) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   vector<vector<int> > rtn;        
   if ( num.size() < 3 ) return rtn;

   sort(num.begin(), num.end());
   vector<int> curr;
   vector<int>::const_iterator it = num.begin();
   threeSumImpl(rtn, num, it, curr);

   return rtn;
}

void threeSumImpl(
      vector<vector<int> >& rtn,
      const vector<int>& num,
      vector<int>::const_iterator& it,
      vector<int>& curr)
{
   int sum = accumulate(curr.begin(), curr.end(), 0);
   if ( curr.size() == 3 )
   {
      if ( sum == 0 ) rtn.push_back(curr);
      return;
   }
   if ( sum + *it > 0 ) return;

   for ( vector<int>::const_iterator iit = it; iit != num.end(); ++iit )
   {
      vector<int> tmpl = curr;
      if ( iit - it > 0 && *(iit - 1) == *iit ) continue;

      tmpl.push_back(*iit);
      vector<int>::const_iterator iiit = iit + 1;
      threeSumImpl(rtn, num, iiit, tmpl);
   }
}
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int h[] = {-2, 1, 0, 1, 2};
   vector<int> height(h, h+sizeof(h)/sizeof(int));
   cout << sol.threeSum(height) << endl;
   return 0;
}
