class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char c : expression) {
            if (c == ',') continue;
            if (c != ')') {
                st.push(c);
            } else {
                // Collect until '('
                vector<char> vals;
                while (!st.empty() && st.top() != '(') {
                    vals.push_back(st.top());
                    st.pop();
                }
                st.pop(); // remove '('
                char op = st.top(); st.pop(); // operator before '('

                bool result;
                if (op == '!') {
                    result = (vals.back() == 'f');
                } else if (op == '&') {
                    result = true;
                    for (char v : vals) result &= (v == 't');
                } else { // '|'
                    result = false;
                    for (char v : vals) result |= (v == 't');
                }
                st.push(result ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};
