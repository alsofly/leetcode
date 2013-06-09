#include <iostream>

class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int h(0), t(n-1);
        bool monotonic(A[t] >= A[h]);
        while ( t - h > 1 )
        {
            int m = (t+h)/2;
            if ( A[m] == target ) return m;
            if ( monotonic )
            {
                if ( A[m] > target ) t = m;
                else h = m;
            }
            else
            {
                if ( A[m] > A[h] )
                {
                    if ( target >= A[h] && target < A[m] ) 
                    {
                        t = m;
                        monotonic = true;
                    }
                    else
                    {
                        h = m;
                    }
                }
                else
                {
                    if ( target > A[m] && target <= A[t] )
                    {
                        h = m;
                        monotonic = true;
                    }
                    else
                    {
                        t = m;
                    }
                }
            }
        }
        
        if ( target == A[h] ) return h;
        else if ( target == A[t] ) return t;
        
        return -1;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
