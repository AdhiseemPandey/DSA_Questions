class Solution {
public:
    int dp[301][7][7][7][7];
    pair<int,int> getCoordinate( char ch){
        int curr = ch - 'A';
        return { curr/6, curr%6 };
    }

    int getDistance(int x1, int y1, int x2, int y2){
        return (abs(x1 - x2) + abs(y1 - y2));
    }

    int solve( string &word,  int i, int x1, int y1, int x2, int y2){
        if( i>= word.length())
            return 0;

        auto [x,y] = getCoordinate(word[i]);
        if( dp[i][x1+1][y1+1][x2+1][y2+1] != -1 ){
            return dp[i][x1+1][y1+1][x2+1][y2+1];
        }

        // koi use nahi hua 
        if( x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1 ){
            return dp[i][x1+1][y1+1][x2+1][y2+1] = solve(word, i+1, x, y, x2, y2);
        }

        // f2 not used 
        if( x2 == -1 && y2 == -1 ){
            int moveF2 = 0 + solve(word, i+1, x1, y1, x, y );
            int moveF1 = getDistance( x1, y1, x, y ) + solve( word, i+1, x, y, x2, y2);
            return dp[i][x1+1][y1+1][x2+1][y2+1] = min(moveF1, moveF2);
        }

        //  both moved 
        int moveF1 = getDistance(x1, y1, x, y) +
                            solve(word, i+1, x, y, x2, y2);
        
        int moveF2 = getDistance(x2, y2, x, y) +
                            solve(word, i+1, x1, y1, x, y);

        return dp[i][x1+1][y1+1][x2+1][y2+1] = min(moveF1, moveF2);

    }

    int minimumDistance(string word) {
        // f1 = x1, y1
        // f2 = x2, y2
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, -1,-1,-1,-1);
    }
};