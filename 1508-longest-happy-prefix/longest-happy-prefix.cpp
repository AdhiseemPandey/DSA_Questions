class Solution {
public:
    string longestPrefix(string s) {
        vector<int> KMP(s.length(), 0);

        // tracks prev longest length
        int maxLen = 0;

        for( int i = 1; i < s.length() ; i++ ){
            if( s[i] == s[maxLen] ){
                maxLen++;
                KMP[i] = maxLen;
            }

            // If mismatch occurs & maxLen is not zero, fallback using KMP
            else if( maxLen != 0 ){
                maxLen = KMP[maxLen - 1];
                i--; // retry with dame i again
            }

            // else no macth - maxLen = 0  
        }

        return s.substr(0, KMP[s.length()-1]);

    }
};



/*
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int maxLen = 0;

        for( int i = n-1 ; i > 0 ; i-- ){
            //  i = length of hte happy prefix
            if( s.substr(0, i) == s.substr(n-i, i) ){
                return s.substr(0, i);
            }
        }
        return "";
    }
};
*/