// two methods - 
// 1) topo sort 
// 2) cycle detection

// IMP for the revision 


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev(V);   // Reverse adjacency list
        vector<int> indegree(V, 0);      // Indegree array

        // Build reverse graph and indegree
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adjRev[it].push_back(i);  // Reverse edge
                indegree[i]++;            // Count outgoing edges in original graph
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        // Start with nodes having 0 outgoing edges (indegree = 0 in reversed graph)
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn’s Algorithm on reversed graph
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
