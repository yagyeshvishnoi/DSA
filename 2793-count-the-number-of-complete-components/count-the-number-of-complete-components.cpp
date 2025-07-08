class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visit(n,false);
        vector<vector<int>> adj(n);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        int count = 0;

        for(int i = 0;i<n;i++){
            if(!visit[i]){
                vector<int> component;
                q.push(i);
                visit[i] = true;
                
                while(!q.empty()){
                    int top = q.front();
                    q.pop();
                    component.push_back(top);
                    
                    for(int neighbor : adj[top]){
                        if(!visit[neighbor]){
                            visit[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                
                bool isComplete = true;
                int componentSize = component.size();
                for(int node : component){
                    if(adj[node].size() != componentSize - 1){
                        isComplete = false;
                        break;
                    }
                }
                
                if(isComplete) count++;
            }
        }
        return count;
    }
};