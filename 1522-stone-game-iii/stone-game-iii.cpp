class Solution {
public:
    int n;              // number of stones
    vector<int> t;      // memoization table
    
    int solve(vector<int>& stoneValue, int i) {
        if (i == n) return 0;          // base case: no stones left
        if (t[i] != -1) return t[i];   // already computed
        
        // Option 1: take 1 stone
        t[i] = stoneValue[i] - solve(stoneValue, i + 1);
        
        // Option 2: take 2 stones
        if (i + 1 < n)
            t[i] = max(t[i], stoneValue[i] + stoneValue[i + 1] - solve(stoneValue, i + 2));
        
        // Option 3: take 3 stones
        if (i + 2 < n)
            t[i] = max(t[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(stoneValue, i + 3));
        
        return t[i];
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        t.assign(n + 1, -1);   // initialize memo table
        
        int diff = solve(stoneValue, 0);  // score difference starting at index 0
        
        if (diff > 0) return "Alice";
        else if (diff < 0) return "Bob";
        else return "Tie";
    }
};

/*

Play optimally - Game Strategy

Game Strategy means - Best From you(max) and Worst from Oppenent(min)

*/