#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<vector<int> > rtn;
        vector<int> curr;
        vector<int>::iterator it = num.begin();
        combinationSum2Impl(rtn, num, it, curr, target);
        return rtn;
    }
    
    void combinationSum2Impl(
        vector<vector<int> >& rtn,
        const vector<int>& candidates,
        vector<int>::iterator& it,
        vector<int>& curr,
        const int target)
    {
        int sum = accumulate(curr.begin(), curr.end(), 0);
        if ( sum == target )
        {
            rtn.push_back(curr);
            return;
        }
        
        if ( sum > target ) return;
        if ( it == candidates.end() ) return;
        
        for ( vector<int>::iterator iit = it; iit != candidates.end(); ++iit )
        {
            vector<int> tmpl = curr;
            if ( (iit - it) > 0 && *(iit-1) == *iit )
            {
                continue;
            }
            tmpl.push_back(*iit);
            vector<int>::iterator iiit = iit + 1;
            combinationSum2Impl(rtn, candidates, iiit, tmpl, target);
        }
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   return 0;
}
