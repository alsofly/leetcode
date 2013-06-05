#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pa(m-1), pb(n-1), curr(m+n-1);
        while ( pa >= 0 && pb >= 0 )
        {
            if ( A[pa] > B[pb] )
            {
                A[curr--] = A[pa--];
            }
            else
            {
                A[curr--] = B[pb--];
            }
        }
        
        while ( pb >= 0 )
        {
            A[curr--] = B[pb--];
        }
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}

