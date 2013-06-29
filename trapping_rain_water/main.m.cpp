#include <iostream>
#include <output.h>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> o(A, A+n), l(o), r(o);
        
        for ( int i = 1; i < n; ++i )
        {
            if ( l[i] < l[i-1] ) l[i] = l[i-1]; 
        }

        for ( int i = n-2; i >= 0; --i )
        {
            if ( r[i] < r[i+1] ) r[i] = r[i+1];
        }
        
        int water(0);
        for ( int i = 0; i < n; ++i )
        {
            water += min(l[i], r[i]) - o[i];
        }
        
        return water;
    }
};

int main()
{
   int A[] = {0, 2, 1, 3, 0};
   Solution sol;
   cout << sol.trap(A, sizeof(A)/sizeof(int)) << endl;
   return 0;
}
