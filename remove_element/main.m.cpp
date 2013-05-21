#include <iostream>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int end(0);
        for ( int i = 0; i < n; ++i )
        {
            if ( A[i] != elem )
            {
                if ( end != i ) swap(A[i], A[end]);
                ++end;
            }
        }
        return end;
    }
    
    void swap(int& a, int& b)
    {
        a = a^b;
        b = a^b;
        a = a^b;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   return 0;
}
