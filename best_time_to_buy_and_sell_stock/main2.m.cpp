#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int maxProfit(vector<int>& prices)
   {
      if ( prices.size() <= 1 ) return 0;
      int maxVal(prices[1] - prices[0]);
      int maxRight(maxVal);

      for ( int i = 1; i < prices.size() - 1; ++i )
      {
         int profit = prices[i+1] - prices[i];
         maxRight = profit + max(0, maxRight);
         maxVal = max(maxVal, maxRight);
      }

      return max(maxVal, 0);
   }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
