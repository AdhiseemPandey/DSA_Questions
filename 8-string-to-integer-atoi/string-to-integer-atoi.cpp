class Solution {
public:
    int myAtoi(string s) {
       int i = 0 ; 
       //skip front zeros
       while(s[i] == ' '){
        i++;
       }
       int sign = 1 ; 
       // check for the optional sign 
       if ( s[i] == '+' || s[i] == '-'){
        if(s[i] == '-'){
            sign = -1 ; 
        }
        i++;
       }
       long result = 0 ; 
       // process the digits and calculate the result 
       while( s[i] >= '0' && s[i] <= '9' ){
        result = result * 10 + ( s[i] - '0');
        // check for overflow adn underflow 
        if ( result * sign > INT_MAX ){
            return INT_MAX;
        }
        if( result * sign < INT_MIN ){
            return INT_MIN;
        }
        i++;
       }
       return (result * sign);
    }
};