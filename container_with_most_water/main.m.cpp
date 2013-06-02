#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

ostream& operator<<(ostream& os, const set<int>& input)
{
   os << '(';
   for ( set<int>::const_iterator it = input.begin();
         it != input.end(); ++it )
   {
      os << *it << ",  ";
   }
   os << ')';
   return os;
}

ostream& operator<<(ostream& os, const multimap<int, int>& input)
{
   os << '[';
   for ( multimap<int, int>::const_iterator it = input.begin();
         it != input.end(); ++it )
   {
      os << '(' << it->first << ',' << it->second << "), ";
   }
   os << ']';
   return os;
}

class Solution {
public:
int maxArea(vector<int> &height) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   multimap<int, int> heightToPos;
   set<int> position;
   for ( int i = 0, len = height.size(); i < len; ++i )
   {
      heightToPos.insert(make_pair(height[i], i));
      position.insert(position.end(), i);
   }
   cout << position << endl;
   cout << heightToPos << endl;

   int area(0);
   for ( multimap<int, int>::const_iterator it = heightToPos.begin();
         it != heightToPos.end(); ++it )
   {
      int leftArea = (it->first)*((it->second)-*position.begin());
      int rightArea = (it->first)*(*position.rbegin() - (it->second));
      area = max(area, max(leftArea, rightArea));
      position.erase(it->second);
      cout << position << endl;
      cout << area << endl;
   }

   return area;
}
};

int main(int argc, const char *argv[])
{
   Solution sol;
//   int height[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int height[] = {10,14,10,4,10,2,6,1,6,12};
   vector<int> h(height, height + sizeof(height)/sizeof(int));
   cout << sol.maxArea(h) << endl;
   
   return 0;
}
