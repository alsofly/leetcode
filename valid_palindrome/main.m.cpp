#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = s.size();
        if ( size == 0 ) return true;
        
        int head(0), tail(size-1);
        while ( head <= tail )
        {
            while ( !is_alphaNum(s[head]) && head <= tail ) {++head;}
            while ( !is_alphaNum(s[tail]) && head <= tail ) {--tail;}
            if ( head > tail ) return true;
            if ( to_lower(s[head]) != to_lower(s[tail]) ) return false;
            ++head;
            --tail;
        }
        
        return true;
    }
    
    bool is_alphaNum(const char c)
    {
        if ( (c >= 'A' && c <= 'Z')
          || (c >= 'a' && c <= 'z')
          || (c >= '0' && c <= '9') ) 
          return true;
        
        return false;
    }
    
    char to_lower(const char c)
    {
        if ( c >= 'A' && c <= 'Z' ) 
            return c - 'A' + 'a';
         
        return  c;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.isPalindrome("race car") << endl;
   return 0;
}
