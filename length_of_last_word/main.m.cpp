#include <iostream>

class Solution {
public:
   int lengthOfLastWord(const char *s) {
      // 1) Go to the end of string
      // 2) scan back to find the first non-space
      // 3) go on to find next space or take the diff
   
      const char *curr = s;
      while ( *curr != '\0' ) ++curr;
      --curr;

      while ( *curr == ' ' && curr != s - 1 )
      {
         --curr;
      }
      if ( curr == s - 1 ) return 0;

      const char *tail = curr;
      while ( *curr != ' ' && curr != s - 1 )
      {
         --curr;
      }

      return tail - curr;
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   std::cout << sol.lengthOfLastWord("Today is a good day ") << std::endl;
   return 0;
}
