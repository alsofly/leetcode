#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size_a(a.size()), size_b(b.size());
        string rtn(max(size_a, size_b), '0');
        int advance(0);
        for ( int i = 1, len = rtn.size(); i <= len; ++i )
        {
            int val = advance 
                      + (i > size_a ? 0 : a[size_a - i] - '0')
                      + (i > size_b ? 0 : b[size_b - i] - '0');
            advance = val/2;
            rtn[len - i] = val % 2 ? '1' : '0';
        }
        
        if ( advance ) rtn = '1' + rtn;
        return rtn;
    }
    
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.addBinary("101", "11100111") << endl;
   return 0;
}
