#include <iostream>

using namespace std;

class Solution {
public:
   int firstMissingPositive(int A[], int n) {
      // Move non-positive number to the end
      int tail(n - 1);
      for ( int i = 0; i < n; ++i )
      {       
         if ( i >= tail ) break;
         while ( A[i] <= 0 && i < tail ) 
         {
            A[i] = A[i]^A[tail];
            A[tail] = A[i]^A[tail];
            A[i] = A[i]^A[tail];
            --tail;
         }
      }
      if ( A[tail] <= 0 ) --tail;

      // Go through the whole array, 
      // mark m-th element negative if meet m ( when m < n )
      for ( int i = 0; i <= tail; ++i )
      {
         if ( abs(A[i]) <= tail + 1 )
         {
            A[abs(A[i])-1] = -abs(A[abs(A[i])-1]);
         }
      }

      // Go through the whole array again,
      // the first positve nubmer's index is the first
      // missing positive
      for ( int i = 0; i <= tail; ++i )
      {
         if ( A[i] > 0 ) return i+1;
      }

      return tail+2;
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int A[] = {3,2,1,6,7,4};
   cout << sol.firstMissingPositive(A, sizeof(A)/sizeof(A[0])) << endl;
   return 0;
}


