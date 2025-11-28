using vi = vector<int>;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; 
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            // Treat i == n as a sentinel (height = 0)
            int h = (i == n ? 0 : heights[i]);

            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};




/*
    using vi = vector<int>;
class Solution {
public:

    vi findNSE(vi &heights) {
        int n = heights.size();
        vi nse(n, n); // default: no smaller element → n
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nse;
    }

    vi findPSE(vi &heights) {
        int n = heights.size();
        vi pse(n, -1); // default: no smaller element → -1
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) { // iterate from right to left
            while (!st.empty() && heights[st.top()] > heights[i]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vi nse = findNSE(heights);
        vi pse = findPSE(heights);
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

*/