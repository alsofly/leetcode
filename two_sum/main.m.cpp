#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = numbers.size();
        vector<int> ret(2,0);
        for ( int i = 0; i < size - 1; ++i )
        {
            for ( int j = i + 1; j < size;  ++j )
            {
                if ( target == numbers[i] + numbers[j] )
                {
                    ret[0] = i + 1;
                    ret[1] = j + 1;
                    return ret;
                }
            }
        }
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;

   return 0;
}
