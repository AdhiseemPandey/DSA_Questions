class Solution {
private:
    void dfs(int node, vector<vector<int>>& LS, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : LS[node]) {
            if (!vis[it]) {
                dfs(it, LS, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> LS(n);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    LS[i].push_back(j);
                    LS[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, LS, vis);
            }
        }
        return cnt;
    }
};
