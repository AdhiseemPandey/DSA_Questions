class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // If k is still > 0, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build result string from stack - "123456.."
        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros - "00100"
        int pos = res.find_first_not_of('0');
        if (pos == string::npos) return "0";
        res = res.substr(pos);

        return res;
    }
};
