class Solution {
    vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // or vector<vector<int>> directions = ...... see beloow changes 
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> minDanger(rows, vector<int>(cols, INT_MAX)); // result vector => min healath to reach [0][0] to [i][j]
        deque<pair<int,int>> bfsQueue;

        minDanger[0][0] = grid[0][0]; // starting cell
        bfsQueue.push_front({0, 0});

        while (!bfsQueue.empty()) {
            auto [row, col] = bfsQueue.front();
            bfsQueue.pop_front();

            for (auto &dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                // BELOW changes are 
                /*
                int nr = r + dir[0]
                int nc = c + dir[1]
                */
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;

                int newCost = minDanger[row][col] + grid[newRow][newCol];
                if (newCost < minDanger[newRow][newCol]) {
                    minDanger[newRow][newCol] = newCost;

                    if (grid[newRow][newCol] == 0) 
                        bfsQueue.push_front({newRow, newCol});
                    else
                        bfsQueue.push_back({newRow, newCol});
                }
            }
        }

        return health - minDanger[rows-1][cols-1] >= 1;
    }
};





/*
class Solution {
    vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> minDanger(rows, vector<int>(cols, INT_MAX));
        using Cell = pair<int, pair<int,int>>; 
        // {dangerCost, {row, col}}

        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        minDanger[0][0] = grid[0][0];
        pq.push({minDanger[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [currCost, pos] = pq.top();
            auto [row, col] = pos;
            pq.pop();

            if (currCost > minDanger[row][col]) continue; // skip outdated entry

            for (auto &dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;

                int newCost = currCost + grid[newRow][newCol];
                if (newCost < minDanger[newRow][newCol]) {
                    minDanger[newRow][newCol] = newCost;
                    pq.push({newCost, {newRow, newCol}});
                }
            }
        }

        return health - minDanger[rows-1][cols-1] >= 1;
    }
};

*/