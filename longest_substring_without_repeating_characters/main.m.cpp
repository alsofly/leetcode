#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxLength(0);
        map<char, int> pos;
        
        int size = s.size();
        int begin = 0;
        for ( int i = 0; i < size; ++i )
        {
            map<char, int>::iterator it = pos.find(s[i]);
            if ( pos.end() == it || it->second < 0 )
            {
                pos[s[i]] = i;
                maxLength = max(maxLength, i - begin + 1);
            }
            else
            {
                for ( int j = begin; j < it->second; ++j )
                {
                    pos[s[j]] = -1;
                }
                begin = it->second + 1;
                it->second = i;
            }
        }
        return maxLength;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfr\
         xsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << endl;
   return 0;
}
