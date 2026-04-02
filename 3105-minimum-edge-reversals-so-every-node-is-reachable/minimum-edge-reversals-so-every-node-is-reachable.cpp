class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    vector<int> ans;

    // Step 1 : Initial DFS node 0 se 
    int dfs(int node, int parent){
        int cost = 0;
        for ( auto &[nbr, wt] : adj[node] ){
            if ( nbr == parent ) continue;
            cost += wt + dfs(nbr, node);
        }
        return cost;
    }

    // Step 2: Rerooting DFS
    void reroot(int node, int parent){
        for ( auto &[nbr,wt] : adj[node] ){
            if ( nbr == parent ) continue;
            if ( wt == 0 ){
                // original edge: node -> nbr
                ans[nbr] = ans[node] + 1;
            }
            else{
                // reverse edge
                ans[nbr] = ans[node] - 1;
            }
            reroot(nbr,node);
        }
    }



    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        ans.resize(n);

        // build graph
        for ( auto &e : edges ){
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v,0}); // correct direction 
            adj[v].push_back({u,1}); // reverse edge
        }
            // Step 1 : Compute for root = 0 
            ans[0] = dfs(0,-1);

            // Step 2 : reroot the root , node 
            reroot(0,-1);

            return ans;
    }
};