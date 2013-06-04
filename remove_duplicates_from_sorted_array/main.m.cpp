#include <iostream>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( n == 0 ) return 0;
        
        int fillTo(1);
        int scanTo(1);
        while ( scanTo < n )
        {
            if ( A[scanTo - 1] != A[scanTo] )
            {
                A[fillTo++] = A[scanTo];
            }
            ++scanTo;
        }
        return fillTo;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;

   
   return 0;
}
