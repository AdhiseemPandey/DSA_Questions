// Three approaches are present 
// TC => O ( N )
// SC => O ( 1 )


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int candies = n; // each child gets at least 1
        int i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candies += peak;
                i++;
            }

            int valley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                valley++;
                candies += valley;
                i++;
            }

            // Correct adjustment: subtract overlap only once
            candies -= min(peak, valley);
        }

        return candies;
    }
};


/*
// Co-polit 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int sum = 1;   // first child gets 1 candy
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                up++;
                peak = up;
                down = 0;
                sum += 1 + up;
            } else if (ratings[i] == ratings[i-1]) {
                up = down = peak = 0;
                sum += 1;
            } else { // ratings[i] < ratings[i-1]
                up = 0;
                down++;
                sum += 1 + down;
                if (down > peak) {
                    sum += 1; // adjust only once when downhill exceeds peak
                }
            }
        }
        return sum;
    }
};


*/




// MY CODE 

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int sum = 1 ;
//         int i = 1 ;
//         int n = ratings.size() ; 
//         while ( i < n ){
//             if ( ratings[ i ] == ratings[ i - 1 ] ){
//                 sum++ ;
//                 i++ ; 
//                 continue ; 
//             }
//             int peak = 0 ;
//             while ( ( i < n ) && ( ratings [ i ] > ratings [ i - 1 ] ) ) {
//                 peak++ ;
//                 sum += peak ; 
//                 i++ ; 
//             }
//             int down = 0 ; 
//             while ( ( i < n ) && ( ratings [ i ] < ratings [ i - 1 ] ) ) {
//                 down++ ;
//                 sum += down ; 
//                 i++ ;
//             }
//             if ( down > peak ) { 
//                 sum += ( down - peak ) ;
//             }    
//         }
//         return sum ; 
//     }
// };
