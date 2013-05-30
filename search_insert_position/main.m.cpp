#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int h(0), t(n-1);
        if ( target <= A[0] ) return 0;
        if ( target > A[n-1] ) return n;
        
        while ( t - h > 1 )
        {
            int m = (t+h)/2;
            if ( A[m] == target ) return m;
            if ( A[m] > target ) t = m;
            else h = m;
        }
        
        if ( A[h] == target ) return h;
        else return t;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
