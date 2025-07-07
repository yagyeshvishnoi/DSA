class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 0;
        vector<int> dp(m, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == '0') dp[j] = 0;
                else dp[j] += 1;
            }
            stack<int> st;
            for(int j = 0; j <= m; j++) {
                int h = (j == m) ? 0 : dp[j];
                while(!st.empty() && dp[st.top()] > h) {
                    int height = dp[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    maxi = max(maxi, height * width);
                }
                st.push(j);
            }
        }
        return maxi;
    }
};