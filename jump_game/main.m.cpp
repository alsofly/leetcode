#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( n == 1 ) return true;
        
        vector<bool> yes(n, false);
        int latestTrue(n - 1);
        for ( int i = n - 2; i >= 0; --i )
        {
            if ( A[i] == 0 ) 
            {
                yes[i] = false;
            }
            else if ( A[i] + i >= n - 1 )
            {
                yes[i] = true;
                latestTrue = i;
            }
            else
            {   
                yes[i] = latestTrue <= i + A[i];
                if ( yes[i] ) latestTrue = i;
            }
        }
        return yes[0];
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int A[] = {2,3,5,9,0,9,7,2,7,9,1,7,4,6,2,1,0,0,1,4,9,0,6,3};
   cout << sol.canJump(A, sizeof(A)/sizeof(int)) << endl;
   return 0;
}
