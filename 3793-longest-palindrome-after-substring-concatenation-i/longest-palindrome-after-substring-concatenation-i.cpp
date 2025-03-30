#define st string 
#define I int
class Solution {
public:
    bool pal(st s){
        for(I i = 0 ; i < s.size(); i++){
            if ( s[i] != s[s.size()-1-i]) return false;
        }
        return true;
    }
    I ans = 0;
    I longestPalindrome(string s, string t) {
        for(I i = 0; i < s.size(); i++) {
            for(I j = i; j <= s.size(); j++) {
                for(I k = 0; k < t.size(); k++) {
                    for(I l = k; l <= t.size(); l++) {
                        if(pal(s.substr(i,j-i) + t.substr(k,l-k))) {
                            ans = max(ans, l + j - i - k);
                        }
                    }
                }
            }
        }
        return ans;
    }
};