#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

#include <output.h>

using namespace std;

class Solution {
public:
int largestRectangleArea(vector<int> &height) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   set<size_t> pos;
   set<size_t, greater<size_t> > posRev;
   multimap<int, size_t, greater<int> > height2pos;
   for ( size_t i = 0; i < height.size(); ++i )
   {
      pos.insert(i);
      posRev.insert(i);
      height2pos.insert(make_pair(height[i], i));
   }
   cout << pos << endl;
   cout << posRev << endl;
   cout << height2pos << endl;

   int maxArea(0);
   for ( multimap<int, size_t>::iterator it = height2pos.begin(), 
         itE = height2pos.end(); it != itE;  )
   {
      int currHeight = it->first;
      multimap<int, size_t>::iterator itUpper = height2pos.upper_bound(currHeight);
      vector<size_t> currRange;
      while ( it != itUpper )
      {
         cout << it->second << endl;
         currRange.push_back(it->second);
         pos.erase(it->second);
         posRev.erase(it->second);
         ++it;
      }
      for ( size_t i = 0; i < currRange.size(); ++i )
      {
         size_t currPos = currRange[i];
         set<size_t>::iterator itB = pos.upper_bound(currPos);
         set<size_t>::iterator itS = posRev.upper_bound(currPos);
         int upperL = itB == pos.end() ? height.size() - 1 : *itB - 1;
         int lowerL = itS == posRev.end() ? 0 : *itS + 1;
         maxArea = max(maxArea, currHeight*(upperL - lowerL + 1));
         cout << lowerL << ", " << upperL << ", " << maxArea << endl;
      }
   }
   return maxArea;
}
};



int main()
{
   Solution sol;
   int h[] = {0, 1, 2, 3, 4, 5};
   vector<int> height(h, h+sizeof(h)/sizeof(int));
   cout << height << endl;
   cout << sol.largestRectangleArea(height) << endl;
   
   return 0;
}
