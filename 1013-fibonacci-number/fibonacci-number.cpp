/*

---------------------------RECURSION
class Solution {
public:
    int fib(int n) {
        if ( n <= 1 ) return n;
        return fib(n-1) + fib(n-2);
    }
};
*/

// -------------------MEMOIZATION
// class Solution {
// public:
//     int helper(int n, vector<int>& dp) {
//         // Base cases
//         if (n <= 1) return n;

//         // If already computed
//         if (dp[n] != -1) return dp[n];

//         // Recurrence relation
//         dp[n] = helper(n-1, dp) + helper(n-2, dp);
//         return dp[n];
//     }

//     int fib(int n) {
//         vector<int> dp(n+1, -1); // memo table
//         return helper(n, dp);
//     }
// };

// ------------------TABULATION
// class Solution {
// public:
//     int helper(int n, vector<int>& dp) {
//        dp[0] = 0;
//        dp[1] = 1; 
//        for( int i = 2 ; i <= n ; i++ ){
//         dp[i] = dp[i-1] + dp[i-2];
//        } 
//        return dp[n];
//     }

//     int fib(int n) {
//         vector<int> dp(n+1, -1); // memo table
//         return helper(n, dp);
//     }
// };

// -----------------SPACE OPTIMIZED
class Solution {
public:
    int helper(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
       int prev2 = 0 ; 
       int prev = 1 ; 
       for( int i = 2 ; i <= n ; i++ ){
        int curr = prev + prev2; 
        prev2 = prev;
        prev = curr;
       } 
       return prev;
    }

    int fib(int n) {
        //vector<int> dp(n+1, -1); // memo table
        return helper(n);
    }
};