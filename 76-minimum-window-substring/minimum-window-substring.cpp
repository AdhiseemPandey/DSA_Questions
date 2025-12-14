class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0, r = 0;
        int cnt = 0;
        int sIndex = -1;
        int minlen = INT_MAX; // or 1e9 ... no 10^9 as XOR operation
        int hash[256] = {0};

        for (int i = 0; i < m; i++) hash[t[i]]++;

        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minlen);
    }
};
