#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > rtn;
        vector<string> pre;
        partition(rtn, pre, s);
        return rtn;
    }
    
    void partition(vector<vector<string> >& out, 
                   vector<string>           pre,
                   const string&            substring)
    {
        for ( int i = 0, len = substring.size(); i < len; ++i )
        {
            string sub = substring.substr(0, i + 1);
            if ( is_palindrome(sub) )
            {
                pre.push_back(sub);
                if ( i == len - 1 ) out.push_back(pre);
                else 
                {
                    partition(out, pre, substring.substr(i+1));
                    pre.pop_back();
                }
            }
        }
    }
    
    bool is_palindrome(const string& s)
    {
        for ( int i = 0, size = s.size(); i < size/2; ++i )
        {
            if ( s[i] != s[size - 1 - i]) return false;
        }
        return true;
    }
};

template <typename T>
ostream& operator<< (ostream& os, const vector<vector<T> > strVecVec)
{
   for ( int i = 0; i < strVecVec.size(); ++i )
   {
      os << "[";
      vector<T> strVec = strVecVec[i];
      for ( int j = 0; j < strVec.size(); ++j )
      {
         os << "'" << strVec[j] << "'" << (j == strVec.size() - 1 ? "" : ",");
      }
      os << "]" << endl;
   }
   return os;
}

int main(int argc, const char *argv[])
{
   Solution sol;
   cout << sol.partition("ccaacabacb") << endl;
   
   return 0;
}
