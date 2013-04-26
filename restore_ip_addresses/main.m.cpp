#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> out;
        spin_off(out, "", 4, s, 0);
        return out;
    }
    
    void spin_off(vector<string>& out, 
                  string          off, 
                  const int       num2go, 
                  const string&   s,
                  const int       from)
    {
        int length = s.size() - from;
        if ( length < num2go || length > 3*num2go ) return;
        
        if ( num2go == 1 )
        {
            string sec(s.substr(from));
            if ( is_valid(sec) ) out.push_back(off + "." + sec);
        }
        else
        {
            int maxNumOfDigit = min(3, length - num2go + 1);
            for ( int i = 1; i <= maxNumOfDigit; ++i )
            {
                string sec(s.substr(from, i));
                if ( is_valid(sec) )
                {
                    string newOff(off + (num2go == 4 ? "" : ".") + sec);
                    spin_off(out, newOff, num2go - 1, s, from + i);
                }
            }
        }        
    }
    
    bool is_valid(const string& s)
    {
        int len = s.size();
        if ( len == 2 && s[0] == '0' ) return false;
        else if ( len == 3 )
        {
            if ( s[0] == '0' ) return false;
            istringstream iss(s);
            int i;
            iss >> i;
            if ( i > 255 ) return false;
        }
        return true;
    }
    
};

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
   for ( int i = 0, len = vec.size(); i < len; ++i )
   {
      os << setw(3) << i << ") " << vec[i] << endl;
   }
   return os;
}

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.restoreIpAddresses("8118294") << endl;
   
   return 0;
}
