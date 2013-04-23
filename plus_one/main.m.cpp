#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> rtn(digits);
        int i = digits.size() - 1;
        for ( ; i >= 0; --i )
        {
            int num = digits[i];
            if ( num != 9 ) 
            {
                rtn[i] = num + 1;
                break;
            }
            else
            {
                rtn[i] = 0;
            }
        }
        
        if ( i >= 0 ) return rtn;
        else 
        {
            vector<int> rtnCopy(digits.size() + 1, 0);
            rtnCopy[0] = 1;
            return rtnCopy;
        }
    }
};

ostream& operator<<(ostream& os, const vector<int>& vec)
{
   for ( int i = 0, size = vec.size(); i < size; ++i )
   {
      os << vec[i] << ", ";
   }
   return os;
}

int main(int argc, const char *argv[])
{
   Solution sol;
   int digits[] = {9, 7, 9, 9};
   vector<int> digitsVec(digits, digits + sizeof(digits)/sizeof(int));
   cout << sol.plusOne(digitsVec) << endl;
   
   return 0;
}
