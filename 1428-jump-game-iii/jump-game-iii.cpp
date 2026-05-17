class Solution {
public:
    bool dfs(vector<int>& arr, int start, vector<bool>& visited) {
    
        if (start < 0 || start >= arr.size() || visited[start]) return false;
    
        if (arr[start] == 0) return true;
     
        visited[start] = true;
        
        return dfs(arr, start + arr[start], visited) || 
               dfs(arr, start - arr[start], visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, start, visited);
    }
};
/*

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(start);
        vis[start] = true;

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if(arr[i] == 0) return true;

            int forward = i + arr[i];
            int backward = i - arr[i];

            if(forward < n && !vis[forward]) {
                vis[forward] = true;
                q.push(forward);
            }

            if(backward >= 0 && !vis[backward]) {
                vis[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};

*/