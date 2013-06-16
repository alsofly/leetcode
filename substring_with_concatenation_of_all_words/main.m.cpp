#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> rtn;
        if ( L.size() == 0 ) return rtn;
        if ( L[0].size() == 0 ) return rtn;
        
        int s = L.size();
        int l = L[0].size();
        int tl = s*l;
        
        map<string, pair<int, int> > Lmap;
        for ( vector<string>::const_iterator it = L.begin();
            it != L.end(); ++it )
        {
            map<string, pair<int, int> >::iterator itM = Lmap.find(*it);
            if ( itM == Lmap.end() )
            {
                Lmap.insert(make_pair(*it, make_pair(1, 0)));
            }
            else
            {
                itM->second.first += 1;
            }
        }
        
        
        for ( int i = 0, len = S.size() -tl + 1; i < len; ++i )
        {
            if ( is_valid(S, i, Lmap, s, l) ) rtn.push_back(i);
        }
        
        return rtn;
    }
    
    bool is_valid(const string &S, int head, 
                map<string, pair<int, int> > Lmap, int s, int l)
    {
        for ( int i = 0; i < s; ++i )
        {
            string curr(S.substr(head + i*l, l));
            map<string, pair<int, int> >::iterator it = Lmap.find(curr);
            if ( it != Lmap.end() )
            {
                if ( it->second.first == it->second.second )
                {
                    return false;
                }
                else
                {
                    it->second.second += 1;
                }
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char *argv[])
{
   
   
   return 0;
}
