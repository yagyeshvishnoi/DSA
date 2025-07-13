class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<tuple<int, int, int>> pq;
        pq.push({0, 0, src});  

        vector<int> dist(n, INT_MAX);  
        dist[src] = 0;  

        while (!pq.empty()) {
            auto [cost, stops, node] = pq.front();
            pq.pop();
            
            if (stops > k) continue; 
            
            for (auto& [next, price] : adj[node]) {
                int newCost = cost + price;

                if (newCost < dist[next]) {
                    dist[next] = newCost;
                    pq.push({newCost, stops + 1, next});
                }
            }
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};
