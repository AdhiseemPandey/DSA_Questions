// DFS Approach 

class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col;

        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if (!dfs(it, !col, color, graph)) return false;
            } else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) return false;
            }
        }
        return true;
    }
};




// BFS CODE 
/*
class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;  // Start coloring with 0

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];  // Assign opposite color
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;  // Conflict found
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);  // Initialize all as uncolored (-1)

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!check(i, graph, color)) return false;
            }
        }
        return true;
    }
};

*/
