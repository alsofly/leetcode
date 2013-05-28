#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for ( int i = 0; i < 9; ++i )
        {
            set<char> unitRow;
            set<char> unitCol;
            set<char> unitSub;
            int subRow(i/3), subCol(i%3);
            for ( int j = 0; j < 9; ++j )
            {
                int inSubRow(j/3 + subRow*3), inSubCol(j%3 + subCol*3);
                if ( board[i][j] == '.' 
                  || unitRow.find(board[i][j]) == unitRow.end() )
                {
                    unitRow.insert(board[i][j]);
                }
                else
                {
                    return false;
                }
                
                if ( board[j][i] == '.'
                  || unitCol.find(board[j][i]) == unitCol.end() )
                {
                    unitCol.insert(board[j][i]);
                }
                else
                {
                    return false;
                }
                
                if ( board[inSubRow][inSubCol] == '.'
                  || unitSub.find(board[inSubRow][inSubCol]) == unitSub.end() )
                {
                    unitSub.insert(board[inSubRow][inSubCol]);
                }
                else
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main(int argc, const char *argv[])
{
   Solution sol;
   
   return 0;
}
