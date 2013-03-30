#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
   int maxSubArray(int A[], int n)
   {
      int maxValue = A[0];
      int maxOnRight = A[0];
      int i = 0;
      for ( ; i < n; ++i )
      {
         maxValue = max(maxValue, A[i]);
         maxOnRight = A[i];
         if ( A[i] > 0 ) break;
      }

      int tempSum  = 0;
      for ( ++i; i < n; ++i )
      {
         if ( A[i] <= 0 ) tempSum += A[i];
         else
         {
            maxOnRight = A[i] + max(0, maxOnRight + tempSum);
            maxValue = max(maxValue, maxOnRight);
            tempSum = 0;
         }
      }

      return maxValue;
   }

   
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int A[] = {31,-41,59,26,-53,58,97,-93,-23,84};
   cout << sol.maxSubArray(A, sizeof(A)/sizeof(int)) << endl;
   return 0;
}
