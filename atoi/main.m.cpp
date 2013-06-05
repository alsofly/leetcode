#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while ( str[0] != '\0' && str[0] == ' ' ) ++str;
        if ( str[0] == '\0' ) return 0;
        
        int sign(1);
        if ( str[0] == '-' ) sign = -1;
        if ( str[0] == '+' || str [0] == '-' ) ++str;
        
        long long rtn(0);
        while ( str[0] >= '0' && str[0] <= '9' && str[0] != '\0' )
        {
            rtn = rtn*10 + str[0] - '0';
            ++str;
        }
        rtn *= sign;
        
        if ( rtn > INT_MAX ) rtn = INT_MAX;
        if ( rtn < INT_MIN ) rtn = INT_MIN;
        
        return rtn;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   char num[] = "   -123ad";
   cout << sol.atoi(num) << endl;
   return 0;
}
