#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size(s.size());        
        if ( 0 == size ) return 0;
        
        int minus1(1), minus2(1);
        if ( !(s[0] >= '1' && s[0] <= '9') )
        {
            minus1 = 0;
        }
        
        for ( int i = 1; i < size; ++i )
        {
            int currEncoding(0);
            int twoDigits = 10*(s[i-1] - '0') + s[i] - '0';
            if ( twoDigits >= 10 && twoDigits <= 26 )
            {
                currEncoding += minus2;
            }
            
            if ( s[i] >= '1' && s[i] <= '9' )
            {
                currEncoding += minus1;
            }
            
            minus2 = minus1;
            minus1 = currEncoding;
            
            if ( minus1 == 0 && minus2 == 0 ) return 0;
        }
        
        return minus1;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.numDecodings("1023244") << endl;
   
   return 0;
}
