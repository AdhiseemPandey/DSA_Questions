class Solution {
public:
    int maxDepth(string s) {
      int ans = 0 ;
      int depth = 0 ; 
      for (auto ch : s){
        if( ch == '(') depth++;
        else if ( ch == ')') depth--;
        ans = ans < depth ? depth : ans ;
      } 
      return ans ;
    }
};


// //BETTER APPROACH => N & N complexity
// int ans = 0 , n = 0 ; 
//        stack<char>ap;
//        for (auto ch : s ){
//         if(ch =='('){
//             ap.push(ch);
//         }
//         else if ( ch ==')'){
//             ap.pop();
//         }
//         n = ap.size();
//         ans = ans < n ? n : ans;
//        } 
//        return ans;