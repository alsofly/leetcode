#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
double kth(int A[], int m, int B[], int n, int k)
{
   if ( m == 0 ) return B[k-1];
   if ( n == 0 ) return A[k-1];

   int la(0), ha(m);
   while ( true )
   {
      int i = (la + ha)/2;
      int j = k - 1 - i ;
      if ( j > n ) j = n;
      else if ( j < 0 ) j = 0;
      i = k - 1 - j;
      double Ai   = i == m ? INT_MAX : A[i];
      double Ai_1 = i == 0 ? INT_MIN : A[i-1];
      double Bj   = j == n ? INT_MAX : B[j];
      double Bj_1 = j == 0 ? INT_MIN : B[j-1];

      if ( Ai >= Bj_1 && Ai <= Bj ) return Ai;
      if ( Bj >= Ai_1 && Bj <= Ai ) return Bj;
      if ( Ai < Bj_1 ) la = i + 1;
      else ha = i; // Ai_1 > Bj
   }
}
 
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
   if ( (m+n)&1 ) return kth(A, m, B, n, (m+n+1)/2);
   else return (kth(A, m, B, n, (m+n)/2) 
              + kth(A, m, B, n, (m+n)/2+1))/2.0;
}
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
