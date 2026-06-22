class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (string &tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if      (tok == "+") st.push(a + b);
                else if (tok == "-") st.push(a - b);
                else if (tok == "*") st.push(a * b);
                else if (tok == "/") st.push(a / b);
            } else {
                st.push(stoi(tok)); // string to int 
            }
        }
        
        return st.top();
    }
};
