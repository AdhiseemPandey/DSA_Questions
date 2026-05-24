class Solution {
public:
    int n ;
    vector<int> memo;
    int solve( vector<int>& arr, int i , int d ){
        int ans = 1;
        if(memo[i] != -1) return memo[i];
        // left me &  0 =< ho check
        for( int j = i-1; j >= max(0, i-d); j-- ){
            if( arr[j] >= arr[i] ) break;
            ans = max(ans, 1 + solve(arr, j, d));
        }

        // right &  < n 
        for( int j = i+1; j <= min(n-1, i+d); j++ ){
            if( arr[j] >= arr[i] ) break;
            ans = max(ans, 1 + solve(arr, j, d));
        }
        return memo[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memo.resize(n+1,-1);
        int ans = 1; 
        for( int i = 0 ; i < n ; i++ ){
            ans = max(ans, solve(arr, i, d));
        }

        return ans;
    }
};



/*

**************************         RECURSION          ********************************
class Solution {
public:
    int n ;

    int solve( vector<int>& arr, int i , int d ){
        int ans = 1;

        // left me &  0 =< ho check
        for( int j = i-1; j >= max(0, i-d); j-- ){
            if( arr[j] >= arr[i] ) break;
            ans = max(ans, 1 + solve(arr, j, d));
        }

        // right &  < n 
        for( int j = i+1; j <= min(n-1, i+d); j++ ){
            if( arr[j] >= arr[i] ) break;
            ans = max(ans, 1 + solve(arr, j, d));
        }
        return ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        int ans = 1; 
        for( int i = 0 ; i < n ; i++ ){
            ans = max(ans, solve(arr, i, d));
        }

        return ans;
    }
};




**************************         Memoization        ********************************

class Solution {
public:
    int n ;
    vector<int> memo;
    int solve( vector<int>& arr, int i , int d ){
        int ans = 1;
        if(memo[i] != -1) return memo[i];
        // left me &  0 =< ho check
        for( int j = i-1; j >= max(0, i-d); j-- ){
            if( arr[j] >= arr[i] ) break;
            ans = max(ans, 1 + solve(arr, j, d));
        }

        // right &  < n 
        for( int j = i+1; j <= min(n-1, i+d); j++ ){
            if( arr[j] >= arr[i] ) break;
            ans = max(ans, 1 + solve(arr, j, d));
        }
        return memo[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memo.resize(n+1,-1);
        int ans = 1; 
        for( int i = 0 ; i < n ; i++ ){
            ans = max(ans, solve(arr, i, d));
        }

        return ans;
    }
};



*************************          Tabulation         ********************************



*/