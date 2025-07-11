class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int> indeg(num, 0);
        vector<vector<int>> adj(num);
        for (auto& p : pre) {
            indeg[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        stack<int> q;
        for (int i = 0; i < num; ++i) {
            if (indeg[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int t = q.top();
            q.pop();
            count++;

            for (int neighbor : adj[t]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return count == num;
    }
};
