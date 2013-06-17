#include <iostream>
#include <vector>
#include <output.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rtn;
        vector<int> perm;
        map<int, int> numM;
        for ( int i = 0; i < num.size(); ++i )
        {
            numM[num[i]]++;
        }
        
        traverse(rtn, perm, numM, num.size()); 
        return rtn;
    }
    
    void traverse(
        vector<vector<int> >& rtn,
        vector<int>& perm,
        map<int, int>& numM,
        int len)
    {
        if ( perm.size() == len )
        {
            rtn.push_back(perm);
            return;
        }
        
        for ( map<int, int>::iterator it = numM.begin();
              it != numM.end(); ++it )
        {
            if ( it->second == 0 ) continue;
            perm.push_back(it->first);
            --(it->second);
            traverse(rtn, perm, numM, len);
            ++(it->second);
            perm.pop_back();
        }
    }
};

int main()
{
   Solution sol;
   int a[] = {1,2,2};
   vector<int> arr(a, a+sizeof(a)/sizeof(int));
   cout << arr << endl;
   cout << sol.permuteUnique(arr) << endl;
   return 0;
}
