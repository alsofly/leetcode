#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
int minimumTotal(vector<vector<int> >& triangle)
{
   if ( triangle.size() == 0 ) return 0;

   vector<int> minSum_candidate(triangle.size(), 0);
   for ( int i = 0; i < triangle.size(); ++i ) 
   {
      minTotal_candiate(triangle, minSum_candidate, i);
   }

   return *min_element(minSum_candidate.begin(), minSum_candidate.end());
}

void minTotal_candidate(vector<vector<int> >& triangle, 
                       vector<int>& totalArr, 
                       int row)
{
   int tempCurrent = totalArr[0];
   totalArr[0] += triangle[row][0];
   for ( let i = 1; i < row; ++i )
   {
      int tempPre = tempCurrent;
      tempPre = totalArr[i];
      totalArr[i] = min(tempPre, tempCurrent) + triangle[row][i];
   }
   totalArr[row] = tempCurrent + triangle[row][row]; 
}

};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
