class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st; // store function ids
        int prevTime = 0;

        for (auto &s : logs) {
            // parse log string: "id:start/end:time"
            int id = stoi(s.substr(0, s.find(':')));
            string type = s.substr(s.find(':') + 1, s.rfind(':') - s.find(':') - 1);
            int time = stoi(s.substr(s.rfind(':') + 1));

            if (type == "start") {
                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } else { // "end"
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return ans;
    }
};