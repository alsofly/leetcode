#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
int minimumTotal(vector<vector<int> >& triangle)
{
   int height = triangle.size();
   vector<pair<int, int> > stack;
   pair<int, int> preNode(0, -1);
   if ( height == 0 ) return 0;
   stack.push_back(pair<int, int>(0, 0));
   int sum = triangle[0][0];
   int minSum = 0;
   for ( int i = 0; i < triangle.size(); ++i )
   {
      minSum += triangle[i][0];
   }

   while ( stack.size() > 0 )
   {
      pair<int, int> currNode(stack.back());
      if ( preNode.second == -1
        || preNode.second + 1 == currNode.second )
      {
         if ( currNode.second != height - 1 )
         {
            stack.push_back(pair<int, int>(currNode.first, currNode.second + 1));
            sum += triangle[currNode.second + 1][currNode.first];
         }
         else if ( sum < minSum )
         {
            minSum = sum;
         }
      }
      else if ( currNode.first == preNode.first 
             && currNode.second == preNode.second - 1 )
      {
         stack.push_back(pair<int, int>(currNode.first + 1, currNode.second + 1));
         sum  += triangle[currNode.second + 1][currNode.first + 1];
      }
      else
      {
         stack.pop_back();
         sum -= triangle[currNode.second][currNode.first];
      }
      preNode = currNode;
   }

   return minSum;
}

};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
