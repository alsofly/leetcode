#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> out;
        string temp("");
        find_parenthesis(out, temp, n, n);
        return out;
    }
    
    void find_parenthesis(vector<string>& out, 
            string& currStr,
            int head, 
            int tail)
    {
        if ( tail == 1 && head == 0 )
        {
            currStr += ')';
            out.push_back(currStr);
            return;
        }
        
        if ( head > 0 )
        {
            string temp(currStr + '(');
            find_parenthesis(out, temp, head-1, tail);
        }
    
        if ( head < tail && tail > 0 )
        {
            string temp(currStr + ')'); 
            find_parenthesis(out, temp, head, tail-1);
        }
    }
};

ostream& operator<<(ostream& os, const vector<string>& in)
{
   for ( int i = 0, size = in.size(); i < size; ++i )
   {
      os << setw(3) << i << ". " << in[i] << endl;
   }
   return os;
}

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.generateParenthesis(5) << endl;
   return 0;
}
