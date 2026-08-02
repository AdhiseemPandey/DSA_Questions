// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
        
//     }
// };



// Approach - As Alice can pick any Odd oR Even Indiex as she starts the game.
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
       int n = piles.size();
       int evenSum = 0, oddSum = 0;
       for ( int i  = 0 ; i < n ; i++ ){
        if( i % 2 == 0 )
            evenSum += piles[i];
        else
            oddSum += piles[i];
       }

       if( evenSum != oddSum ) return true;


       return false;
    }
};