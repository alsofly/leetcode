#include <iostream>
#include <vector>
#include <string>

using namespace std;

ostream& operator<<(ostream& os, const vector<string>& input)
{
   os << "[";
   for ( vector<string>::const_iterator it = input.begin();
         it != input.end(); ++it )
   {
      os << *it << ", ";
   }
   os << "]";
   return os;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> rtn;
        string curr("");
        letterCombinationsImpl(rtn, digits, curr);
        return rtn;
    }
    
    void letterCombinationsImpl(
        vector<string>& rtn,
        const string& digits,
        const string& curr)
    {
        if ( curr.size() == digits.size() )
        {
            rtn.push_back(curr);
            return;
        }
        
        char num = digits[curr.size()];
        char start = 'a' + (num - '2')*3;
        if ( num > '7' ) ++start;
        char end = start + 3;
        if ( start == 'p' || start == 'w' ) ++end; 
        
        for ( ; start < end; ++start )
        {
            string next(curr + start);
            letterCombinationsImpl(rtn, digits, next);
        }
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.letterCombinations("932") << endl; 
   
   return 0;
}
