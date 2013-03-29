class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( m == 1 || n  == 1 ) return 1;
        
        if ( m < n )
        {
            int k = m;
            m = n;
            n = k;
        }
        return factorial(m+n-2, m)/factorial(n-1, 1);
        
    }
    
    double factorial(int n, int m) { // n > m
        double rtnVal = 1;
        while ( n >= m ) 
        {
            rtnVal *= n;
            n--;
        }
        return rtnVal;
    }
};
