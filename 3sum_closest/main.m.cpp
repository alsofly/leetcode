#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int closest(num[0] + num[1] + num[2]);
        vector<int>::const_iterator it = num.begin();
        threeSumClosest(closest, num, it, 0, 0, target);
        return closest;
    }
    
    void threeSumClosest(
        int& closest,
        const vector<int> &num,
        vector<int>::const_iterator& it,
        int currSize,
        int sum,
        const int target)
    {
        if ( currSize == 3 )
        {
            if ( abs(sum - target) < abs(closest - target) )
                closest = sum;
            return;
        }
        
        if ( currSize == 2 
          && sum + *it > target 
          && abs(sum + *it - target) > abs(closest - target) ) return; 
        
        for ( vector<int>::const_iterator iit = it; iit != num.end(); ++iit )
        {
            if ( iit - it > 0 && *(iit - 1) == *iit ) continue;
            vector<int>::const_iterator iiit = iit + 1;
            threeSumClosest(closest, num, iiit, currSize+1, sum + *iit, target);
        }
    }
    
    
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
