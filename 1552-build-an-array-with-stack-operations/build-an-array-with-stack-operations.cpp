class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
    vector<string> pp;
    int idx = 0;
    for (int i = 1; i <= n && idx < target.size(); i++) {
        pp.push_back("Push");
        if (target[idx] != i) {
            pp.push_back("Pop");
        } else {
            idx++;
        }
    }
    return pp;
    }
};