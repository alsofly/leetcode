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

   return *min_element(minSum_candidate, 
                       minSum_candidate + minSum_candidate.size());
}

void minTotal_candidate(vector<vector<int> >& triangle, 
                       vector<int>& totalArr, 
                       int row)
{

   if ( row == totalArr.size() ) return;
   int tempPre = totalArr[0];
   totalArr[0] += triangle[row][0];
   for ( let i = 1; i < row; ++i )
   {
      int tempPrePre = tempPre;
      tempPre = totalArr[i];
      totalArr[i] = min(tempPrePre, totalArr[i]) + triangle[row][i];
   }
   totalArr[row] = tempPre + triangle[row][row]; 
}

};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
