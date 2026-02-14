class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>> adj(v);

        // Build adjacency list
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // Compute in-degrees
        vector<int> inDegree(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        // Push nodes with in-degree 0
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        // BFS (Kahn  Algorithm)
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }

        return count == v;
    }
};
