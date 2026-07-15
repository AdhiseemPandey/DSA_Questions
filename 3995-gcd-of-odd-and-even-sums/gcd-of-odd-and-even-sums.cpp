class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0; 
        int even = 0;

        for( int i = 0 ; i < n ; i++ ){
            odd += ((2*i)+1);
            even += ((2*i)+2);
        }

        return __gcd(odd, even);
    }
};