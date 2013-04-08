#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
string longestPalindrome(string s) {
   int head(0), tail(0);
   int identHead(0), identTail(0);
   set<int> curr;
   curr.insert(0);
   for ( int i = 1; i < s.size(); ++i )
   {
      if ( s[i] == s[identHead] )
      {
         identTail = i;
         if ( identTail - identHead > tail - head )
         {
            tail = identTail;
            head = identHead;
         }
      }
      else
      {
         identHead = i; 
         identTail = i;
      }

      set<int> temp;
      for ( set<int>::iterator it = curr.begin(); it != curr.end(); ++it )
      {
         int currHead = *it;
         if ( currHead - 1 >= 0
           && s[currHead - 1] == s[i] 
           && currHead - 1 <= identHead )
         {
            temp.insert(currHead - 1);
            if ( i - currHead + 1 > tail - head )
            {
               tail = i;
               head = currHead - 1;
            }
         }
         temp.insert(i);
         if ( s[i] == s[i-1] ) temp.insert(i-1);
      }
      curr = temp;
   }
   return s.substr(head, tail - head + 1);
}
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.longestPalindrome("tattarrrattat") << endl; 
   return 0;
}
