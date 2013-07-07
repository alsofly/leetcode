#include <iostream>
#include <vector>
#include <algorithm>
#include <output.h>

using namespace std;

class Solution {
public:
    struct CompObj {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        }
    } compObj;
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< pair<int, int> > nums;
        for ( int i = 0, len = numbers.size(); i < len; ++i )
        {
            nums.push_back(pair<int, int>(numbers[i], i+1));
        }
        
        sort(nums.begin(), nums.end(), compObj);
        
        int head(0), tail(numbers.size() - 1);
        while ( head < tail )
        {
            int curr = nums[head].first + nums[tail].first - target;
            if ( curr > 0 )
            {
                --tail;
            }
            else if ( curr < 0 )
            {
                ++head;
            }
            else 
            {
                break;
            }
        }
        
        vector<int> rtn(2);
        rtn[0] = min(nums[head].second, nums[tail].second);
        rtn[1] = max(nums[head].second, nums[tail].second);
        return rtn;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int v[] = {150,24,79,50,88,345,3};
   vector<int> vec(v, v+sizeof(v)/sizeof(int));
   cout << sol.twoSum(vec, 200) << endl;
   
   return 0;
}
