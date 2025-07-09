class Solution {
public:
    void helper(int n, vector<vector<int>>& adj, int top, vector<int>& indeg, vector<int>& ans, queue<int>& q){
        for(auto curr : adj[top]){
            indeg[curr]--;
            if(indeg[curr] == 0){
                ans.push_back(curr);
                q.push(curr);
            }
        }
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        
        for(auto i : pre){
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        
        queue<int> q;
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                ans.push_back(i);
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            helper(n, adj, top, indeg, ans, q);
        }
        
        if(ans.size() == n) return ans;
        return {};
    }
};