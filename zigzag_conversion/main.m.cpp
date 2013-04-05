#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if ( 1 == nRows ) return s;
        
        int size = s.size();
        ostringstream oss;
        for ( int i = 0, j = (nRows-1)*2; j*i < size; ++i )
        {
            oss << s[j*i];
        }
        
        for ( int k = 1; k < nRows - 1; ++k )
        {
            for ( int i = 0, j = (nRows-1)*2; j*i < size; ++i )
            {
                if ( j*i + k < size ) oss << s[j*i +k];
                if ( j*(i+1) - k < size ) oss << s[j*(i+1)-k];
            }
        }
        
        for ( int i = 0, j = (nRows-1)*2; j*i + nRows - 1 < size; ++i )
        {
            oss << s[j*i + nRows -1];
        }
        
        return oss.str();
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.convert("abcafdsvaveewfdvd", 4) << endl;
   return 0;
}
