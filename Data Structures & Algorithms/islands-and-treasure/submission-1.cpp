class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto direction : directions) {
                int newX = x + direction[0];
                int newY = y + direction[1];

                if(newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size() || grid[newX][newY] != INT_MAX) {
                    continue;
                }

                grid[newX][newY] = grid[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }
};
