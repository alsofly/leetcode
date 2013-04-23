#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( n == 0 ) return 1;
        if ( n == 1 ) return 1;
        int first(1), second(1);
        for ( int i = 2; i <= n; ++i )
        {
            int next = first + second;
            first = second;
            second = next;
        }
        return second;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.climbStairs(10) << endl;
   return 0;
}
