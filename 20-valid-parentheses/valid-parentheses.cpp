class Solution {
public:
    bool isValid(string s) {
        stack<char> holder;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                holder.push(s[i]); 
            } else {
                if (holder.empty()) return false;
                char ch = holder.top();
                holder.pop();
                if ((s[i] == ')' && ch != '(') ||
                    (s[i] == '}' && ch != '{') ||
                    (s[i] == ']' && ch != '[')) {
                    return false;
                }
            }
        }
        return holder.empty();
    }
};
