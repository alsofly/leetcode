#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( x < 0 ) return false;
        int num = 0;
        while ( x/base10(num) > 9 ) { ++num; }
        for ( int i = num; i > 0; i -= 2 )
        {
            int base = base10(i);
            int high = x/base;
            int low = x % 10;
            if ( high != low ) return false;
            x = (x - high*base)/10;
        }
        
        return true;
    }
    
    int base10(int order)
    {
        int ret(1);
        while ( order > 0 ) {ret *= 10; --order; }
        return ret;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.isPalindrome(1000660001) << endl;
   
   return 0;
}
