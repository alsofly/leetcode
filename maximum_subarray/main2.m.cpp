#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
int maxSubArray(int A[], int n)
{
   int maxValue(A[0]), maxOnRight(A[0]);
   for( int i =1; i < n; ++i )
   {
      maxOnRight = A[i] + max(maxOnRight, 0);
      maxValue = max(maxValue, maxOnRight);
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
