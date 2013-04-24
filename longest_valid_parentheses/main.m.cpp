#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
int longestValidParentheses(string s) {
   int longest(0);                   // longest valid up to now
   int height(0);                    // current height
   map<int, pair<int, int> > ht2itv; // mapping height to interval

   ht2itv[height] = pair<int, int>(0, 0);
   for ( int i = 0, size = s.size(); i < size; ++i )
   {
      int step = cal_step(s[i]);
      if ( step < 1 )
      {
         map<int, pair<int, int> >::iterator it = ht2itv.find(height);
         (it->second).first = -1;
         (it->second).second = -1;
      }

      height += step;
      map<int, pair<int, int> >::iterator it = ht2itv.find(height);
      if ( it == ht2itv.end() )
      {
         ht2itv[height] = pair<int, int>(i+1, i+1);
      }
      else
      {
         if ( (it->second).second == -1 )
         {
            (it->second).first = i + 1;
            (it->second).second = i + 1;
         }
         else
         {
            (it->second).second = i + 1;
            int dist = (it->second).second - (it->second).first;
            longest = max(dist, longest);
         }
      }
   }
   return longest;
}

int cal_step(char c)
{
   return c == '(' ? 1 : -1;
}

};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.longestValidParentheses(")(") << endl;
   
   return 0;
}

