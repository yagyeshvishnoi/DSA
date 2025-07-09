class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
            }
            if(grid[i][m-1] == 1){
                q.push({i, m-1});
            }
        }
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1){
                q.push({0, j});
            }
            if(grid[n-1][j] == 1){
                q.push({n-1, j});
            }
        }
        vector<int> dx = {0, 1, -1, 0};
        vector<int> dy = {1, 0, 0, -1};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            grid[x][y] = 0;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};