#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
   int ladderLength(string start, string end, set<string> &dict) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      
      // insert end to set 
      dict.insert(end);

      // enqueue first element
      queue<pair<string, int> > queue;
      set<string> visited;
      queue.push(pair<string, int>(start, 1));
      visited.insert(start);

      // walking
      while ( queue.size() > 0 )
      {
         int currLevel = queue.front().second;
         string currStr(queue.front().first);
         queue.pop();
         if ( end.compare(currStr) == 0 ) return currLevel; 

         for ( int j = 0; j < currStr.size(); ++j )
         {
            for ( int i = 'a'; i <= 'z'; ++i )
            {
               if ( currStr[j] != i )
               {
                  string tempStr(currStr);
                  tempStr[j] = i;
                  if ( dict.find(tempStr) != dict.end()
                        && visited.find(tempStr) == visited.end() )
                  {
                     cout << "enqueue [" << tempStr << "] @ level = " << currLevel + 1 <<  endl;
                     queue.push(pair<string, int>(tempStr, currLevel+1));
                     visited.insert(tempStr);
                  }
               }
            }
         }
      }

      return 0;
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   string dictArr[] = {"hot", "cog", "dog", "tot", "hog", "hop", "pot", "dot"};
   set<string> dict (dictArr, dictArr + sizeof(dictArr)/sizeof(*dictArr));
   cout << sol.ladderLength("hot", "dog", dict) << endl;
   
   return 0;
}
