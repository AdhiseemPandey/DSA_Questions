class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        // t[i] = maximum jumps starting from index i
        vector<int> t(n, 1);
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(begin(vec), end(vec));

        for (auto& it : vec) {
            int val = it.first;
            int i   = it.second;

            // move left
            for (int j = i - 1; j >= max(0, i - d); j--) {
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }

            // move right
            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }
        }

        return *max_element(begin(t), end(t));
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

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        // t[i] = maximum jumps starting from index i
        vector<int> t(n, 1);

        
        //    In recursion + memoization:
        //    solve(i) depends on smaller elements only.
        //   So in bottom-up, process smaller values first.
        
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(begin(vec), end(vec));

        for (auto& it : vec) {
            int val = it.first;
            int i   = it.second;

            // move left
            for (int j = i - 1; j >= max(0, i - d); j--) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }

            // move right
            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }
        }

        return *max_element(begin(t), end(t));
    }
};


*/