/*
Step 1 : Find the final L. ( i=0 to n-1 )
Step 2 : i = n-1 to i = 0 ( undo ) & keep changing L & K if required
         if( L==K ) return s[i];
Step 3 : FOR "#"
         L = L/2;           }
         K = K-L;           } => if( k >= L)
         a to z : L--;      }
        
         FOR "%" : reverse the result and no length L change 
         K : L-K-1 ( k formula )

         FOR "*" 
         if(s[i] == '*' ) L++; no change in K;
*/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        long long L = 0;

        for(char &ch : s) {
            if(ch == '*') {
                if(L > 0)
                    L--;
            } else if(ch == '#') {
                L *= 2;
            } else if(ch == '%') {
                //reverse - no change in L
                continue;
            } else { //'a' to 'z'
                L++;
            }
        }

        if(k >= L) {
            return '.';
        }

        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '*') {
                L++; //no change in k
            } else if(s[i] == '%') {
                //no change in L
                k = L - k - 1;
            } else if(s[i] == '#') {
                L = L/2;
                k = (k >= L) ? k - L : k;
            } else { //'a' to 'z'
                L--;
            }

            if(k == L) {
                return s[i];
            }
        }

        return '.';

    }
};


/*
// MEMORY LIMIT EXCEEDED
class Solution {
public:
    char processStr(string s, long long k) {
        string result = "";

        for(char &ch : s) {
            if(ch == '*') {
                if(!result.empty()) result.pop_back();
            } else if(ch == '#') {
                result += result;
            } else if(ch == '%') {
                reverse(result.begin(), result.end());
            } else {
                result += ch;
            }
        }

        long long a = result.size();
        if(k >= a) {
            return '.';
        }
        return result[k];
    }
};

*/