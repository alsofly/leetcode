#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> rtn(rowIndex + 1, 1);
        
        for ( int i = 2; i <= rowIndex; ++i )
        {
            for ( int j = i - 1; j > 0; --j )
            {
                rtn[j] += rtn[j-1];
            }
        }
        return rtn;
    }
};

ostream& operator<<(ostream& os, const vector<int>& vec)
{
   os << '[';
   for ( int i = 0, size = vec.size(); i < size; ++i )
   {
      os << vec[i] << ',';
   }
   os << ']';
   return os;
}

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.getRow(10) << endl;
   
   return 0;
}
