class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<long long> dist(n, LLONG_MAX);

        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();
            if (time > dist[u]) continue;
            for (auto &[v, wt] : adj[u]) {
                long long total = time + wt;
                if (total < dist[v]) {
                    dist[v] = total;
                    ways[v] = ways[u];
                    pq.push({total, v});
                } else if (total == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
