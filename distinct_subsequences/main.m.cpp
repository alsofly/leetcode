#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
   int numDistinct(string S, string T) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function

      map<string, map<int, int> > snMap;
      for ( string::iterator it = T.begin(); 
            it != T.end(); ++it )
      {
         if ( snMap.find(string(1, *it)) == snMap.end() )
         {
            cout << string(1, *it) << endl;
            map<int, int> countMap;
            snMap.insert(pair<string, map<int, int> >(string(1, *it), countMap));
         }
      }

      int i = 0;
      for ( string::iterator it = S.begin();
            it != S.end(); ++it )
      {
         map<string, map<int, int> >::iterator snIt = snMap.find(string(1, *it));
         if ( snIt != snMap.end() )
         {
            cout << "[" << string(1, *it) << "]: " << i << endl;
            (snIt->second).insert(pair<int, int>(i, 0));
            ++i;
         }

      }

      map<int, int> backOne;
      map<int, int> frontOne;
      for ( string::reverse_iterator rit = T.rbegin();
            rit != T.rend(); ++rit )
      {
         // copy front -> back
         backOne.clear();
         backOne.insert(frontOne.begin(), frontOne.end());

         // init front from the snMap for current character
         map<string, map<int, int> >::iterator snIt = snMap.find(string(1, *rit));
         frontOne.clear();
         frontOne.insert((snIt->second).begin(), (snIt->second).end());

         // count the sum in frontOne based on backOne
         if ( rit == T.rbegin() )
         {
            for ( map<int, int>::reverse_iterator countIt = frontOne.rbegin();
                  countIt != frontOne.rend(); ++countIt )
            {
               countIt->second = 1;
               cout << "for [sn = " << countIt->first << "] set [count = " << countIt->second << "]" << endl;
            }
         }
         else
         {
            int head = (frontOne.rbegin())->first;
            int tail = S.size();
            int count(0);
            for ( map<int, int>::reverse_iterator countIt = frontOne.rbegin();
                  countIt != frontOne.rend(); ++countIt )
            {
               if ( countIt != frontOne.rbegin() )
               {
                  tail = head;
                  head = countIt->first;
               }
               map<int, int>::iterator low, up;
               cout << "head = " << head << ", tail = " << tail << endl;
               low = backOne.lower_bound(head + 1);
               up = backOne.upper_bound(tail);
               for ( map<int, int>::iterator sumIt = low; sumIt != up; ++sumIt )
               {
                  count += sumIt->second;
               }
               countIt->second = count;
               cout << "for [sn = " << countIt->first << "] set [count = " << countIt->second << "]" << endl;
            }
         }
      }

      if ( frontOne.size() == 0 ) return 0;
      else 
      {
         int sum = 0;
         for ( map<int, int>::iterator it = frontOne.begin();
               it != frontOne.end(); ++it )
         {
            sum += it->second;
         }
         return sum;
      };
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;
//   cout << sol.numDistinct("hasbbbeqit", "habit") << endl;
   cout << sol.numDistinct("abbdcacbabacbabbacaddabbbaaadaadcbcababbbcdccaac", "dabca") << endl;
   
   return 0;
}


