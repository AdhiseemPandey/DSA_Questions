class Solution {
public:
    int reversed( int x ){
        int rev = 0 ; 
        while ( x > 0 ){
            
            int digit = x % 10; 
            rev = rev * 10 + digit;
            x /= 10;
            
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int ans = reversed(n);
        return abs(ans-n);
    }
};