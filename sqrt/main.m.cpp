class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( 0 == x ) return 0;
        double guess = guess_seed(x);
        while (  abs((guess + x/guess)/2 - guess) >= 1 )
        {
            guess = (guess + x/guess)/2;
        }
        double guessInt = ceil(guess);
        while ( guessInt * guessInt > x )
        {
            guessInt--;
        }
        return guessInt;
    }
    
    int guess_seed(int x) {
        int numOfDigit = 0;
        while ( x > 0 )
        {
            numOfDigit++;
            x /= 10;
        }
        
        if ( numOfDigit/2*2 == numOfDigit )
            return pow(10, numOfDigit/2);
        else 
            return pow(10, numOfDigit/2) * 3;
    }
};
