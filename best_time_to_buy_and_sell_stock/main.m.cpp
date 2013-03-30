#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
   int maxProfit(vector<int>& prices)
   {
      if ( prices.size() <= 1 ) return 0;

      int maxValue = prices[1] - prices[0];
      int maxOnRight = maxValue;
      int i = 0;
      for ( ; i < prices.size() - 1; ++i )
      {
         int priceDiff = prices[i+1] - prices[i];
         maxValue = max(maxValue, priceDiff);
         maxOnRight = priceDiff;
         if ( priceDiff > 0 ) break;
      }

      int tempDiffSum = 0;
      for ( ++i; i < prices.size() - 1; ++i )
      {
         int priceDiff = prices[i+1] - prices[i];
         if ( priceDiff <= 0 ) tempDiffSum += priceDiff;
         else
         {
            maxOnRight = priceDiff + max(0, maxOnRight + tempDiffSum);
            maxValue = max(maxValue, maxOnRight);
            tempDiffSum = 0;
         }
      }

      return max(maxValue, 0);
   }
};
