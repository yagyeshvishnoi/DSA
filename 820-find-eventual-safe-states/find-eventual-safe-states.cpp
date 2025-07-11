class Solution {
public:
    bool helper(vector<vector<int>>& graph, vector<int>& issafe, vector<bool>& visit, int curr){
        if(graph[curr].size() == 0 || issafe[curr] == 1){
            issafe[curr] = 1;
            return true;
        }
        
        for(auto c : graph[curr]){
            if(visit[c]) return false;
            if(issafe[c] == 0){
                visit[c] = true;
                if(helper(graph, issafe, visit, c)){
                    issafe[c] = 1;
                }
                else{
                    issafe[c] = -1;
                    visit[c] = false;
                    return false;
                }
                visit[c] = false;
            }
            else if(issafe[c] == -1) return false;
            else if(issafe[c] == 1) continue;
        }
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visit(n, false);
        vector<int> issafe(n, 0);
        vector<int> result;
        
        for(int i = 0; i < n; i++){
            if(issafe[i] != 1){
                visit[i] = true;
                if(helper(graph, issafe, visit, i)){
                    issafe[i] = 1;
                }
                else{
                    issafe[i] = -1;
                }
                visit[i] = false;
            }
        }
        for(int i = 0; i < n; i++){
            if(issafe[i] == 1){
                result.push_back(i);
            }
        }
        
        return result;
    }
};