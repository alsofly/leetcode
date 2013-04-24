#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign = x == abs(x) ? 1 : -1;
        x *= sign;
        
        int rtn(0);
        while ( x > 0 ) 
        {
            rtn = rtn * 10 + x % 10;
            x /= 10;
        }
        return rtn * sign;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.reverse(-123) << endl;
   
   return 0;
}
