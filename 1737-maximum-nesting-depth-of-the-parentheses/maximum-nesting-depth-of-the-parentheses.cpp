class Solution {
public:
    int maxDepth(string s) {
       int ans = 0 , n = 0 ; 
       stack<char>ap;
       for (auto ch : s ){
        if(ch =='('){
            ap.push(ch);
        }
        else if ( ch ==')'){
            ap.pop();
        }
        n = ap.size();
        ans = ans < n ? n : ans;
       } 
       return ans;
    }
};