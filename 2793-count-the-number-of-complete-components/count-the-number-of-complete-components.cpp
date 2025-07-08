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
                vector<int> arr(n,0);
                q.push(i);
                visit[i] = true;
                
                while(!q.empty()){
                    int top = q.front();
                    q.pop();
                    arr[top]++;
                    
                    for(int neighbor : adj[top]){
                        if(!visit[neighbor]){
                            visit[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                
                bool isComplete = true;
                int componentSize = 0;
                for(int j = 0;j<n;j++){
                    if(arr[j] > 0) componentSize++;
                }
                
                for(int j = 0;j<n;j++){
                    if(arr[j] > 0){
                        if(adj[j].size() != componentSize - 1){
                            isComplete = false;
                            break;
                        }
                    }
                }
                
                if(isComplete) count++;
            }
        }
        return count;
    }
};