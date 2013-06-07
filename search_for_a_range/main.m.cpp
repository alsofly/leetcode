#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int upper = upper_bound(A, n, target);
        int lower = upper_bound(A, n, target - 1);
        
        vector<int> rtn;
        if ( upper == lower )
        {
            rtn.push_back(-1);
            rtn.push_back(-1);
            return rtn;
        }
        
        rtn.push_back(lower);
        rtn.push_back(upper-1);
        return rtn;
        
    }
    
    int upper_bound(int A[], int n, int target)
    {
        int head(0), tail(n-1);
        while ( tail - head > 1 )
        {
            int mid = (head+tail)/2;
            if ( A[mid] <= target ) head = mid;
            else tail = mid;
        }
        
        if ( A[head] > target ) return head;
        if ( A[head] <= target && A[tail] > target ) return tail;
        if (A[tail] <= target ) return tail + 1;
    }
};

int main(int argc, const char *argv[])
{
   int A[] = {1, 2, 3, 4, 4, 4, 5, 6};
   Solution sol;
   vector<int> out = sol.searchRange(A, sizeof(A)/sizeof(int), 4);
   cout << out[0] << ", " << out[1] << endl;

   return 0;
}
