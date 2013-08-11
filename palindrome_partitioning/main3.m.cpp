class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > out;
        vector<string> curr;
        partition(out, curr, s, 0);
        return out;
    }
    
    void partition(
        vector<vector<string> >& out,
        vector<string>& curr,
        const string& s,
        int pr)
    {
        if ( pr == s.size() )
        {
            out.push_back(curr);
            return;
        }
        
        for ( int i = pr; i < s.size(); ++i )
        {
            string sub = s.substr(pr, i - pr + 1);
            if ( is_palindrome(sub) )
            {
                curr.push_back(sub);
                partition(out, curr, s, i + 1);
                curr.pop_back();
            }
        }
    }
    
    bool is_palindrome(const string& s)
    {
        int i(0), j(s.size()-1);
        while ( i < j )
        {
            if ( s[i++] != s[j--] ) return false;
        }
        return true;
    }
};

