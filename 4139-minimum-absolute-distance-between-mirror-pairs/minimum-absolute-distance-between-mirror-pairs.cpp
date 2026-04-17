class Solution {
public:
    int reversed(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> prev;
        int ans = n+1;
        for( int i = 0 ; i < n ; i++ ){
            int x = nums[i];
            if( prev.count(x)){
                ans = min(ans, i - prev[x]);
            }
            prev[reversed(x)] = i;
        }
        return ans == n+1 ? -1 : ans; 
    }
};
