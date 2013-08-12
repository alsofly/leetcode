#include <iostream>
#include <output.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length(board.size());
        int width(board[0].size());
        
        map<int, bool> marked;
        for ( int i = 0; i < length; ++i )
        {
            for ( int j = 0; j < width; ++j )
            {
                if ( search(board, length, width, marked, word, 0, i, j) ) return true;
            }
        }
        
        return false;
    }
    
    bool search(
        vector<vector<char> > &board, 
        int length,
        int width,
        map<int, bool>& marked,
        string& word,
        int pos,
        int x,
        int y)
    {
        if ( pos == word.size() ) 
        {
            return true;   
        }
        
        if ( x < 0 || x >= length || y < 0 || y >= width ) 
        {
            return false;
        }
        
        map<int, bool>::iterator it = marked.find(x*width + y);
        if ( it != marked.end() && it->second == true )
        {
            return false;
        }
        
        if ( board[x][y] == word[pos] )
        {
            if ( it == marked.end() ) marked.insert(make_pair(x*width+y, true));
            else it->second = true;
            
            if ( search(board, length, width, marked, word, pos+1, x+1, y) ) return true;
            if ( search(board, length, width, marked, word, pos+1, x, y+1) ) return true;
            if ( search(board, length, width, marked, word, pos+1, x-1, y) ) return true;
            if ( search(board, length, width, marked, word, pos+1, x, y-1) ) return true;
            
            it = marked.find(x*width + y);
            it->second = false;
        }
        
        return false;
    }
};

int main()
{
   Solution sol;

}

