#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
        map<int, bool> map_result;
        return isInterleave(s1, s2, s3, 0, 0, map_result);
    }
    
    bool isInterleave(string& s1, string& s2, string& s3, int p1, int p2,
                map<int, bool>& map_result)
    {
        map<int, bool>::const_iterator it = map_result.find(p1*(s2.size() + 1) + p2); 
        if ( it != map_result.end() ) return it->second;
        
        bool rtn(false);
        if ( p1 == s1.size() ) 
        {
            rtn = s3.substr(p1+p2) == s2.substr(p2);
        }
        else if ( p2 == s2.size() )
        {
            rtn = s3.substr(p1+p2) == s1.substr(p1);
        }
        else
        {
            char& next = s3[p1+p2];
            if ( s1[p1] == next && isInterleave(s1, s2, s3, p1+1, p2, map_result)  
              || s2[p2] == next && isInterleave(s1, s2, s3, p1, p2+1, map_result) ) 
            {    
                rtn = true;
            }
        }
        
        map_result.insert(make_pair(p1*(s2.size() + 1) + p2, rtn));
        return rtn;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   string s1("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa");
   string s2("babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab");
   string s3("babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
   cout << sol.isInterleave(s1, s2, s3) << endl;
   
   return 0;
}
