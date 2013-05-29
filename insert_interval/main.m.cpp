#include <iostream>
#include <vector>

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
   vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      vector<Interval> rtnIntervals;
      bool newIntervalIsIn(false);
      for ( int i = 0, len = intervals.size(); i < len; ++i )
      {   
         if ( intervals[i].end < newInterval.start )
         {
            rtnIntervals.push_back(intervals[i]);
         }
         else if ( intervals[i].start > newInterval.end )
         {
            if ( !newIntervalIsIn )
            {
               rtnIntervals.push_back(newInterval);
               newIntervalIsIn = true;
            }
            rtnIntervals.push_back(intervals[i]);
         }
         else
         {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
         }     
      }

      if ( !newIntervalIsIn )
      {
         rtnIntervals.push_back(newInterval);
      }

      return rtnIntervals;
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;

   return 0;
}
