#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<char> parenStack;
        for ( int i = 0, size = s.size(); i < size; ++i )
        {
            char currChar = s[i];
            if ( currChar == '(' || currChar == '[' || currChar == '{' )
            {
                parenStack.push_back(currChar);
                continue;
            }
            
            if ( parenStack.size() == 0 ) return false;
            char lastChar = parenStack.back();
            parenStack.pop_back();
            switch (currChar)
            {
                case ')':
                    if ( lastChar != '(' ) return false;
                    break;
                case ']':
                    if ( lastChar != '[' ) return false;
                    break;
                case '}':
                    if ( lastChar != '{' ) return false;
                    break;
            }
        }
        
        if ( parenStack.size() > 0 ) return false;
        return true;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.isValid("([{}{}])") << endl;
   
   return 0;
}
