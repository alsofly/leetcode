#include <iostream>
#include <vector>
#include <unordered_set>
#include <output.h>

using namespace std;

class Solution {
public:
int longestConsecutive(vector<int> &num) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   unordered_set<int> hash;
   for ( int i = 0, len = num.size(); i < len; ++i )
   {
      hash.insert(num[i]);
   }
   
   int rtn(0);
   for ( int i = 0, len = num.size(); i < len; ++i )
   {
      rtn = max(rtn, get_count(hash, num[i], -1) + get_count(hash, num[i]+1, 1));
   }
   return rtn;
}

int get_count(unordered_set<int>& hash, int x, int step)
{
   int count = 0; 
   while ( hash.count(x) )
   {
      ++count;
      hash.erase(x);
      x += step;
   }
   return count;
}
};

int main()
{
   Solution sol;
   int n[] = {100, 1, 2, 200, 3, 5};
   vector<int> num(n, n + sizeof(n)/sizeof(int));
   cout << sol.longestConsecutive(num) << endl;
   return 0;
}
