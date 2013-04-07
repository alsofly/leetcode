#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
string minWindow(string S, string T) {
   map<char, pair<int, int> > charCount;
   int included = 0;
   pair<int, int> window(pair<int, int>(-1, -1));
   for ( int i = 0; i < T.size(); ++i )
   {
      char& curr = T[i];
      if ( charCount.find(curr) == charCount.end() )
      {
         charCount.insert(pair<char, pair<int, int> >(curr, pair<int, int>(1, 0)));
      }
      else
      {
         pair<int, int> temp = (charCount.find(curr))->second;
         (charCount.find(curr))->second = pair<int, int>(temp.first + 1, 0);
      }
   }

   int head(0), tail(0);
   for ( int i = 0; i < S.size(); ++i )
   {
      char& curr = S[i];
      map<char, pair<int, int> >::iterator it = charCount.find(curr);
      tail++;
      if ( it != charCount.end() )
      {
         (it->second) =
            pair<int, int>((it->second).first, (it->second).second + 1);
         if ( (it->second).first == (it->second).second ) 
         {
            included++;
            if ( included == charCount.size() )
            {
               map<char, pair<int, int> >::iterator headIt 
                  = charCount.find(S[head]);
               while ( headIt == charCount.end() 
                    || (headIt->second).second > (headIt->second).first )
               {
                  if ( headIt != charCount.end() )
                  {
                     headIt->second = 
                        pair<int, int>((headIt->second).first, (headIt->second).second - 1);
                  }
                  headIt = charCount.find(S[++head]);
               }
               
               if ( window.first == -1 || tail-head < window.second - window.first )
               {
                  window = pair<int, int>(head, tail);
               }
                  headIt->second = pair<int, int>((headIt->second).first, (headIt->second).first -1);
               included--;
               head++;
            }
         }
      }
   }

   if ( window.first == -1 ) return "";
   else return S.substr(window.first, window.second - window.first);
}
};

int main(int argc, const char *argv[])
{
   string s(argv[1]);
   string t(argv[2]);
   Solution sol;
   
   cout << "@SOLUTION: " << sol.minWindow(s, t) << endl;
   cout << "@S = [" << s << "]" << endl;
   cout << "@T = [" << t << "]" << endl;
   
   return 0;
}
