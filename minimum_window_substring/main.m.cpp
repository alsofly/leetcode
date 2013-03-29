#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;


class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int shortestLength = 0;
        int covered = 0;  // num of char in T covered by current range
        int length = 0;   // length of current range 
        int start = -1;
        int end  = -1;
        map<char, int> countMap; 
        for ( string::iterator it = T.begin(); it != T.end(); ++it )
        {
            if ( countMap.find(*it) == countMap.end() )
            {
                countMap.insert(pair<char, int>(*it, 0));
                cout << *it << endl;
            }
        }
        int size = countMap.size(); // num of unique char in T
        
        if ( size == 1 )
        {
            if (S.find(T[0]) == string::npos) return string("");
            return T.substr(0,1); 
        }
        
        queue<string> SInPieces;
        int pieceStart(-1);
        int pieceLen(1);
        for ( int i = 0; i < S.size(); ++i )
        {
           cout << "*i = " << i << endl;
            if ( countMap.find(S[i]) == countMap.end() )
            {
              
                pieceLen++;
            }
            else
            {
                cout << "S[" << i << "]: " << S[i] << endl;
                if ( pieceStart != -1 )
                {
                   cout << "push in %" << S.substr(pieceStart, pieceLen) << "%" << endl;
                    SInPieces.push(S.substr(pieceStart, pieceLen));
                    length += pieceLen;
                }
                else
                {
                    start = i;
                    cout << "set start = " << i << endl;
                }
  
                cout << "increment count" << endl;
                int count = countMap[S[i]];
                if ( count == 0 ) covered++;
                ((countMap.find(S[i]))->second)++;
                
                if ( covered == size )
                {
                   cout << "Found a match!! #"  << S.substr(i - length, length + 1) << "#" << endl;
                   if ( length + 1 < shortestLength || shortestLength == 0 )
                   {
                      shortestLength = length + 1;
                      end = i;
                      cout << "set end = " << end << ", shortestLength = " << shortestLength << endl;
                   }

                   // pop out from front
                   string &firstInStack = SInPieces.front();
                   int numOfChar = firstInStack.size();
                   int numInCountMap = (countMap.find(firstInStack[0]))->second;
                   string firstOfFirst = firstInStack.substr(0, 1);
                   while ( numInCountMap > 1 )
                   {
                        cout << "pop out before string @" << firstInStack << "@" << endl;
                        length -= numOfChar;
                        start += numOfChar;
                        ((countMap.find(firstOfFirst[0]))->second)--;
                        SInPieces.pop();
                        cout << "at here!" << endl;
                        string &firstInStack = SInPieces.front();
                        firstOfFirst.assign(firstInStack.substr(0,1));
                        numOfChar = firstInStack.size();
                        numInCountMap = (countMap.find(firstInStack[0]))->second;
                        cout << "at here!" << endl;
                   }

                   if ( length + 1 <= shortestLength )
                   {
                      shortestLength = length + 1;
                      end = i;
                      cout << "again set end = " << end << ", shortestLength = " << shortestLength << endl;
                   }

                   string &rightNowFirst = SInPieces.front();
                   length -= rightNowFirst.size();
                   start += rightNowFirst.size();
                   covered--;
                   ((countMap.find(rightNowFirst[0]))->second)--;
                   cout << "pop out at string @" << rightNowFirst << "@" << endl;
                   SInPieces.pop();

                   // pop all next in queue as long as there are more in queue of the same char
                   string &nextInStack = SInPieces.front();
                   numOfChar = nextInStack.size();
                   numInCountMap = (countMap.find(nextInStack[0]))->second;
                   string firstOfNext = nextInStack.substr(0,1);
                   while ( numInCountMap > 1 )
                   {
                        cout << "pop out after string @" << nextInStack << "@" << endl;
                      length -= nextInStack.size();
                      start += nextInStack.size();
                      ((countMap.find(firstOfNext[0]))->second)--;
                      SInPieces.pop();
                      string &nextInStack = SInPieces.front();
                      firstOfNext.assign(nextInStack.substr(0,1));
                      numOfChar = nextInStack.size();
                      numInCountMap = (countMap.find(nextInStack[0]))->second;
                   }
                }

                pieceStart = i;
                pieceLen = 1;
                
            }
        }
        
        if ( end == -1 ) return string("");
        else return S.substr(end - shortestLength + 1, shortestLength);
        
    }
};

int main(int argc, const char *argv[])
{
//   string s("cabefgecdaecf");
//   string t("cae");
   string s(argv[1]);
   string t(argv[2]);
   Solution sol;
   
   cout << endl << endl;
   cout << endl << endl << "@" << endl << "@SOLUTION: " << sol.minWindow(s, t) << endl;
   cout << "@S = [" << s << "]" << endl;
   cout << "@T = [" << t << "]" << endl;
   
   return 0;
}
