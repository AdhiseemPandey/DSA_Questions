// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> holder;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
//                 holder.push(s[i]); 
//             } else {
//                 if (holder.empty()) return false;
//                 char ch = holder.top();
//                 holder.pop();
//                 if ((s[i] == ')' && ch != '(') ||
//                     (s[i] == '}' && ch != '{') ||
//                     (s[i] == ']' && ch != '[')) {
//                     return false;
//                 }
//             }
//         }
//         return holder.empty();
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char x : s){
            if(x == '(' || x =='{' || x == '[' ){
                st.push(x);
            }else if(x == ')' || x == '}'|| x == ']'){
                
                if(st.empty())return false;
                char top = st.top();
                if((x == ')' && top!= '(')||
                   (x == '}' && top!= '{')||
                   (x == ']' && top!= '[')){
                    return false;
             }
                st.pop();
                
            }
        }
       return st.empty();; 
    }
};
