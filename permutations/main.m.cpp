#include <iostream>
#include <vector>
#include <output.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rtn;
        vector<int> stack;
        vector<bool> flag(num.size(), false);
        permuteImpl(num, flag, stack, rtn);
        return rtn;
    }
    
    void permuteImpl(
        const vector<int>& num,
        vector<bool>& flag,
        vector<int>& stack,
        vector<vector<int> >& rtn)
    {
        if ( stack.size() == num.size() )
        {
            rtn.push_back(stack);
            return;
        }
        
        for ( int i = 0, len = num.size(); i < len; ++i )
        {
            if ( flag[i] == true ) continue;
            flag[i] = true;
            stack.push_back(num[i]);
            permuteImpl(num, flag, stack, rtn);
            stack.pop_back();
            flag[i] = false;
        }
    }
};

int main()
{
   Solution sol;
   int n[] = {1, 3, 4};
   vector<int> num(n, n+sizeof(n)/sizeof(int));
   cout << sol.permute(num) << endl;
   return 0;
}
