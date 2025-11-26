using vi = vector<int>;
using ll = long long;

class Solution {
public:
    vector<int> findNSE(vi& arr) {
        int n = arr.size();
        vector<int> nse(n, n); // default to n (no smaller element)
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vi& arr) {
        int n = arr.size();
        vector<int> psee(n, -1); // default to -1 (no smaller/equal element)
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                psee[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        ll total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            ll left = i - psee[i];
            ll right = nse[i] - i;
            total = (total + (left * right % mod) * arr[i]) % mod;
        }
        return (int)total;
    }
};

/*
TC => O(5N)
SC => O(5N)
*/

