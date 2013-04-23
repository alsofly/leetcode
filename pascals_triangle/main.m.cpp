#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rtn;
        if ( numRows <= 0 ) return rtn;
        rtn.push_back(vector<int>(1, 1));
        
        for ( int i = 1; i < numRows; ++i )
        {
            vector<int> thisRow(i+1);
            thisRow[0] = 1;
            thisRow[i] = 1;
            vector<int>& ref = rtn.back(); 
            for ( int j = 1; j < i; ++j )
            {
                thisRow[j] = ref[j-1] + ref[j];
            }
            rtn.push_back(thisRow);
        }
        
        return rtn;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   sol.generate(4);
   
   return 0;
}
