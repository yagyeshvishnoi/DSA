class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        if(grid[0][0] == 1)return -1;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        pq.push({1,{0,0}});
        dist[0][0] = 1;
        vector<int> dx = {0,1,1,1,0,-1,-1,-1};
        vector<int> dy = {1,1,0,-1,-1,-1,0,1};

        while(!pq.empty()){
            int wt = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(wt>dist[x][y])continue;
            for(int i = 0;i<8;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!=1){
                    if(dist[nx][ny]>wt+1){
                        dist[nx][ny] = wt+1;
                        pq.push({wt+1,{nx,ny}});
                    }
                }
            } 
        }        
        return dist[n-1][m-1] != INT_MAX ? dist[n-1][m-1] : -1;
    }
};