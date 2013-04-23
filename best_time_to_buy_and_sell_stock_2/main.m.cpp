#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int profit(0);
        for ( int i = 1, size = prices.size(); i < size; ++i )
        {
            profit += max(0, prices[i] - prices[i-1]);
        }
        return profit;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   int prices[] = {1,2,3,4,5,4,5};
   vector<int> pricesVec(prices, prices + sizeof(prices)/sizeof(int));
   cout << sol.maxProfit(pricesVec) << endl;
   
   return 0;
}
