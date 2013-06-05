#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
struct SortComp {
   bool operator()(const Interval& a, const Interval& b) {
      return a.start < b.start;
   }
} sortComp;

vector<Interval> merge(vector<Interval> &intervals) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   vector<Interval> rtn;
   if ( intervals.size() == 0 ) return rtn;

   sort(intervals.begin(), intervals.end(), sortComp);

   rtn.push_back(intervals[0]);
   for ( int i = 1, len = intervals.size(); i < len; ++i )
   {
      Interval& pre = *rtn.rbegin();
      Interval& curr = intervals[i];
      if ( curr.start <= pre.end )
      {
         pre.end = max(pre.end, curr.end);
      }
      else
      {
         rtn.push_back(curr);
      }
   }

   return rtn;
}
};

ostream& operator<<(ostream& os, const vector<Interval>& input)
{
   os << "[";
   for (vector<Interval>::const_iterator it = input.begin(), 
         itE = input.end(); it != itE; ++it )
   {
      os << "[" << it->start << "," << it->end << "], ";
   }
   os << "]";
   return os;
}

int main(int argc, const char *argv[])
{
   Solution sol;
   vector<Interval> input;
   input.push_back(Interval(1, 4));
   input.push_back(Interval(2, 5));
   cout << sol.merge(input) << endl;
   return 0;
}
