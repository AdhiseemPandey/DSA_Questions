using vss = vector<vector<string>>;
using vs  = vector<string>;
using st = string; 
class Solution {
private: 
    void func(int idx , st s , vs & path , vss & res ){
        if (idx == s.size()) {
        res.push_back(path);
        return;
    }

        for ( int i = idx ; i < s.size() ; i++ ){
            if ( isPalindrome( s , idx , i ) ){
                path.push_back( s.substr ( idx , i - idx + 1 ));
                func ( i+1 , s , path , res );
                path.pop_back();
            }
        }
    }
        bool isPalindrome(const st &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
public:
    vss partition(st s) {
        vss res ; 
        vs path ; 
        func ( 0 , s , path , res );
        return res ;       
    }
};