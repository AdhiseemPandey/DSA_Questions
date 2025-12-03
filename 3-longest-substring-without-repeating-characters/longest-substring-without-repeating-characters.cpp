// TC => O(N)
// SC => O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // using mmset for performance 
        int hash[256];
        // mmset works for 0 and -1 
        memset(hash,-1,sizeof(hash));

        int l = 0 ;
        int r = 0 ; 
        int maxLen = 0 ; 
        int n = s.size() ;
        while ( r < n ){
            if( hash[s[r]] != -1 ){
                if( hash[s[r]] >= l ){
                    l = hash[s[r]] + 1 ; 
                } 
            }
            int len = r - l + 1 ; 
            maxLen = max( len, maxLen );
            hash[s[r]] = r ; 
            r++;
        }
        return maxLen;
    }
};

// Approach 2 - Generate substrings and hash on the way TC => O(N^2) & SC => O(256)