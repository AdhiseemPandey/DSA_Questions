class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    // (0.0) pe 1 nahi ho sakta,  starting me nahi and giv echeck : return -1
    // Level pe traverse & vis array 
    // 8 dir = loop and delRow and newRow concept dx,dy
    // boundaries 
    // steps / cnt with each level
    int n = grid.size();

        
        vector<vector<int>> distance(n, vector<int>(n, -1));

        // if blocked 
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)  
            return -1;

        // BFS queue
        queue<pair<int,int>> q;
        q.push({0, 0});
        distance[0][0] = 1;  

        // Directions: 8 moves daigonal bhi
        int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            
            if (x == n-1 && y == n-1)  
                return distance[x][y];

            // Explore neighbors
            for (int dir = 0; dir < 8; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n 
                    && grid[nx][ny] == 0 && distance[nx][ny] == -1) {
                    
                    distance[nx][ny] = distance[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1; // No path found
    






    // we can optimize visited by marking geid[x][y] = 1 
    }
};