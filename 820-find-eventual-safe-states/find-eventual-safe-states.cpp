class Solution{
public:

    bool dfs(vector<vector<int>> &graph, vector<int> &terminal, vector<int> &vis,int curr){
        if(vis[curr] == 1)return false;
        if(terminal[curr] == 1)return true;
        if(terminal[curr] == -1)return false;

        vis[curr] = true;
        for(int i = 0 ; i<graph[curr].size();i++){
            int num = graph[curr][i];
            if(!dfs(graph,terminal,vis,num)){

                terminal[curr] = -1;
                return false;
            }
        }
        terminal[curr] = 1;
        vis[curr] = 0;
        return true;
     }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> terminal(n,0);
        vector<int> vis(n,0);
        for(int i = 0 ; i < n ; i++ ){
            if(graph[i].empty())terminal[i] = 1;
        }
        vector<int> ans;
        for(int i = 0 ; i< n; i++){
            if(dfs(graph,terminal,vis,i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};