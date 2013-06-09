#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <output.h>

using namespace std;

class Solution {
public:
vector<string> fullJustify(vector<string> &words, int L) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   vector<string> rtn;
   for ( int i = 0, len = words.size(); i < len; )
   {
      int numOfWord(0);
      int wordsLen(0);
      int currLen(0);
      while ( i + numOfWord < len
            && words[i + numOfWord].size() + currLen <= L )
      {
         currLen += words[i+numOfWord].size() + 1;
         wordsLen += words[i+numOfWord].size();
         ++numOfWord;
      }

      ostringstream oss;
      if ( numOfWord == 1 )
      {
         oss << words[i];
         oss << setw(L - words[i].size()) << setfill(' ') << "";
      }
      else if ( numOfWord + i == len )
      {
         for ( int j = i; j < len; ++j )
         {
            oss << words[j] << (j == len - 1 ? "" : " ");
         }
         oss << setw(L - oss.str().size()) << setfill(' ') << "";
      }
      else
      {
         int padSize = (L - wordsLen)/(numOfWord - 1);
         int morePadNum = (L - wordsLen) % (numOfWord - 1);
         for ( int j = i; j < i + numOfWord; ++j )
         {
            oss << words[j];
            if ( j - i < numOfWord - 1 )
            {
               oss << setw(padSize) << setfill(' ') << "";
               if ( j - i < morePadNum )
               {
                  oss << " ";
               }
            }
         }
      }
      rtn.push_back(oss.str());

      i += numOfWord;
   }
   return rtn;
}
};

int main(int argc, const char *argv[])
{
   vector<string> words;
   words.push_back("Here");
   words.push_back("is");
   words.push_back("an");
   words.push_back("example");
   words.push_back("of");
   words.push_back("text");
   words.push_back("justification.");
   
   Solution sol;
   cout << words << endl;
   cout << sol.fullJustify(words, 16) << endl;
   
   return 0;
}
