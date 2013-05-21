#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<vector<int> > vec)
{
   os << "[\n";
   for ( int i = 0, len = vec.size(); i < len; ++i )
   {
      os << '[';
      const vector<int>& curr = vec[i]; 
      for ( int j = 0, currLen = curr.size(); j < currLen; ++j )
      {
         os << curr[j] << ", ";
      }
      os << "],\n";
   }
   os << "]\n";
   return os;
}

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > out;
        vector<int> curr;
        combine(out, curr, 1, n, k);
        return out;
    }
    
    void combine(
        vector<vector<int> >& out,
        vector<int> curr,
        int pos,
        int n,
        int k )
    {
        if ( curr.size() == k ) 
        {
            out.push_back(curr);
            return;
        }
        
        if ( pos == n + 1 ) return;
        
        combine(out, curr, pos+1, n, k);
        curr.push_back(pos);
        combine(out, curr, pos+1, n, k);
    }
    
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.combine(5, 3) << endl;
   return 0;
}
