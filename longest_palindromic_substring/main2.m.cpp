#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

// For the string of length n, there are 2*n - 1 possible centers
// including spaces b/t two adjascent characters.
//
// Loop through all possible centers
//    * expand around the current center symetrically on both 
//      left and right to find the max palindrome around current
//      position
//    * record the maximum size centered at current position
//    * search backward from current position to find a position
//      where,
//       1) the longest palindrome centered there is a prefix of 
//          the current longest alindrome. 
//    * move to the symmetric position of that position as the new
//      center
//
//      http://www.akalin.cx/longest-palindrome-linear-time
//      http://johanjeuring.blogspot.com/2007/08/finding-palindromes.html
string longestPalindrome(string s) {
   int len = s.size();
   vector<int> lenArr(2*len - 1, 0);

   for ( int i = 0; i < lenArr.size(); ++i )
   {
      cout << "i = " << i << endl;
      // find the longest panlindrome centered at i
      int curr = (i + 1)/2;
      int panLen = 1 - i&1;
      while ( curr - 1 >= 0 
           && curr + panLen <= len - 1 
           && s[curr-1] == s[curr+panLen] )
      {
         curr--;
         panLen += 2;
      }
      lenArr[i] = panLen;

      int inspect = i - 1;
      while ( inspect >= i - lenArr[i] + 1 )
      {
         if ( inspect - lenArr[inspect] <= i - lenArr[i] )
            break;
         else
         {
            lenArr[2*i - inspect] = lenArr[inspect];
            inspect--;
         }
      }

      i = 2*i - inspect;
      if ( inspect <= i - lenArr[i] ) i--; 
   }

   int center(0);
   int panSize(0);
   for ( int i = 0; i < lenArr.size(); ++i )
   {
      cout << "centered @ [" << i <<  "] ";
      if ( lenArr[i] > 0 )
      {
         cout << s.substr((i-lenArr[i]+1)/2, lenArr[i]) << endl;
      }
      else
      {
         cout << endl;
      }
      if ( lenArr[i] > panSize )
      {
         panSize = lenArr[i];
         center = i;
      }
   }

   return s.substr((center - panSize + 1)/2, panSize);
}
};

int main(int argc, const char *argv[])
{
   Solution sol;
   string s("aabbaa");
   cout << "stirng is [" << s << "]" << endl;
   cout << sol.longestPalindrome(s) << endl; 
   return 0;
}
