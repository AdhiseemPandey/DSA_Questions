// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if ( dividend == divisor ) return 1;

//         bool sign = true ; 
//         if ( dividend >= 0 && divisor < 0 ) sign = false ;
//         else if ( dividend <= 0 && divisor > 0 ) sign = false; 
//         long n = abs(dividend);
//         long d = abs(divisor);
//         divisor = abs(divisor);

//         long quotient = 0 ; 
//         while( n >= d ){
//             int cnt = 0 ; 
//             while ( n >= ( d << ( cnt + 1 ))){
//                 cnt += 1 ; 
//             }
//             quotient +=  1 << cnt ; 
//             n -= ( d << cnt );

//         }
//         if( quotient == ( 1 << 31 ) && sign ){
//             return INT_MAX ;
//         }
//         if ( quotient == ( 1<< 31 ) && !sign ){
//             return INT_MIN ; 
//         }
//         return sign ? quotient : -quotient ;
//     }
// };



// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         // Edge case: overflow
//         if (dividend == INT_MIN && divisor == -1) return INT_MAX;

//         // Determine sign
//         bool sign = (dividend >= 0) == (divisor >= 0);

//         // Work with absolute values (use long to avoid overflow)
//         long n = labs(dividend);
//         long d = labs(divisor);

//         long quotient = 0;
//         while (n >= d) {
//             long temp = d, multiple = 1;
//             while (n >= (temp << 1)) {
//                 temp <<= 1;
//                 multiple <<= 1;
//             }
//             n -= temp;
//             quotient += multiple;
//         }

//         return sign ? (int)quotient : -(int)quotient;
//     }
// };


#include <climits>
#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: overflow when dividing INT_MIN by -1
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Determine sign of result
        bool sign = (dividend >= 0) == (divisor >= 0);

        // Convert to long long before taking absolute value to avoid overflow
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long quotient = 0;
        while (n >= d) {
            long long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            quotient += multiple;
        }

        // Apply sign
        quotient = sign ? quotient : -quotient;

        // Clamp result to int range
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};
