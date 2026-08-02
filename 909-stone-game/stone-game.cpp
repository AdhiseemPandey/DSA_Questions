class Solution {
public:
    int n;
    int t[501][501];
    int solve(vector<int>& piles, int i, int j) {
        if(i > j)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];

        int choose_i  = piles[i]  + min(solve(piles, i+2, j), solve(piles, i+1, j-1)); // took i , BOB has to choose i+1 or j-1 idx
        int choose_j = piles[j] + min(solve(piles, i, j-2), solve(piles, i+1, j-1)); // took j , BOB has to choose i or j-2
        
        return t[i][j] = max(choose_i, choose_j);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));
        int sum = accumulate(begin(piles), end(piles), 0);
        int alexScore = solve(piles, 0, n-1);
        
        return alexScore > sum/2;
    }
};


// Approach - As Alice can pick any Odd oR Even Indiex as she starts the game.
// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//        int n = piles.size();
//        int evenSum = 0, oddSum = 0;
//        for ( int i  = 0 ; i < n ; i++ ){
//         if( i % 2 == 0 )
//             evenSum += piles[i];
//         else
//             oddSum += piles[i];
//        }

//        if( evenSum != oddSum ) return true;


//        return false;
//     }
// };