#define ll long long 
class Solution {
public:
    long long sumAndMultiply(int n) {
        ll x = 0 ; 
        ll sum = 0 ; 
        ll pow10 = 1 ; 

        while ( n > 0 ){
            int digit = n % 10 ; 
            sum += digit ;

            if( digit > 0 ){
                x += digit* pow10 ; 
                pow10 *= 10 ;
            }

            n /= 10 ;
        }
        return x * sum ;
    }
};