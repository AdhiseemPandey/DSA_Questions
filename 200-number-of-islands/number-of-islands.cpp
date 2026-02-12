// class Solution {
// void bfs( int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid ){
//     vis[row][col] = 1;
//     queue<pair<int,int>>q;
//     q.push( { row,col}  );
//     int n = grid.size();
//     int m = grid[0].size();

//     while( ! q.empty() ){
//         int row = q.front().first;
//         int col = q.front().second;
//         q.pop();

//         // traverse the neighbours and mark them visited 
//         for ( int delRow = -1 ; delRow <= 1 ; delRow++ ){
//             for ( int delCol = -1 ; delCol <= 1 ; delCol++ ){
//                 int nRow = row + delRow ; 
//                 int nCol = col + delCol ; 
//                 if ( nRow >= 0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] =='1' && !vis[nRow][nCol] ){
//                     vis[ nRow ][ nCol ] = 1; 
//                     q.push( { nRow, nCol } );
//                 }
//             }
//         } 
//     }

// }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis ( n, vector<int>(m,0) );
//         int cnt = 0 ; 
//         for ( int row = 0; row < n ; row++){
//             for ( int col = 0 ; col < m ; col++ ){
//                 if ( !vis[row][col] && grid[row][col] == '1' ){
//                     cnt ++ ; 
//                     bfs ( row, col , vis , grid );
//                 }
//             }
//         }
//         return cnt;
//     }
// };




// BFS Soluton 
// class Solution {
//     void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
//         vis[row][col] = 1;
//         queue<pair<int,int>> q;
//         q.push({row, col});
//         int n = grid.size();
//         int m = grid[0].size();

//         // 4-directional movement
//         int dRow[] = {-1, 0, 1, 0};
//         int dCol[] = {0, 1, 0, -1};

//         while (!q.empty()) {
//             int r = q.front().first;
//             int c = q.front().second;
//             q.pop();

//             for (int i = 0; i < 4; i++) {
//                 int nRow = r + dRow[i];
//                 int nCol = c + dCol[i];
//                 if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
//                     grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
//                     vis[nRow][nCol] = 1;
//                     q.push({nRow, nCol});
//                 }
//             }
//         }
//     }

// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         int cnt = 0;

//         for (int row = 0; row < n; row++) {
//             for (int col = 0; col < m; col++) {
//                 if (!vis[row][col] && grid[row][col] == '1') {
//                     cnt++;
//                     bfs(row, col, vis, grid);
//                 }
//             }
//         }
//         return cnt;
//     }
// };



// DFS - Recursive solution 
class Solution {
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        // 4-directional movement
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
                dfs(nRow, nCol, vis, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    dfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};
