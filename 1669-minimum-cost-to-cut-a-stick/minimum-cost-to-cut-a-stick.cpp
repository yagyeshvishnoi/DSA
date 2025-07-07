class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int l = 2;l<m;l++){
            for(int i = 0;i+l<m;i++){
                int j = i+l;
                dp[i][j] = INT_MAX;

                for(int k = i+1;k<j;k++){
                    int cost = cuts[j]-cuts[i]+(dp[i][k]+dp[k][j]);
                    dp[i][j] = min(dp[i][j],cost);
                }
            }
        }
        return dp[0][m-1];
    }
};