#include <iostream>
#include <vector>
#include <climits>

using namespace std;

ostream& operator<<(ostream& os, const vector<int> vec)
{
   os << '[';
   for ( int i = 0, size = vec.size(); i < size; ++i )
   {
      os << vec[i] << ',';
   }
   os << ']';
   return os;
}

class Solution {
public:
int jump(int A[], int n) 
{
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
   if ( n == 1 ) return 0;

   vector<int> steps(n, 0);
   vector<int> stepsize(n, 0);
   for ( int i = n  - 2; i >= 0; --i )
   {
      if ( A[i] == 0 )
      {
         steps[i] = INT_MAX;
         stepsize[i] = 0;
      }
      else if ( i + A[i] >= n - 1 )
      {
         steps[i] = 1;
         stepsize[i] = n - 1 - i;
      }
      else
      {
         int step(INT_MAX);
         for ( int j = i + 1; j <= i + A[i]; ++j )
         {
            if ( steps[j] < INT_MAX )
            {
               while ( j + stepsize[j] <= i + A[i] )
               {
                  j += stepsize[j];
               }
            }

            if ( steps[j] < step ) 
            {
               step = steps[j];
               stepsize[i] = j - i;
            }
         }
         steps[i] = (step < INT_MAX ? step + 1 : INT_MAX);
      }
   }
   cout << steps << endl;
   return steps[0];
}
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int A[] = {2,3,5,9,0,9,7,2,7,9,1,7,4,6,2,1,0,0,1,4,9,0,6,3};
   cout << sol.jump(A, sizeof(A)/sizeof(int)) << endl;

   return 0;
}
