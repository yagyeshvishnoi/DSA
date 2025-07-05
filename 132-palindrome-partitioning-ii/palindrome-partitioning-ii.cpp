class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int end = 0; end < n; ++end) {
            int minCut = end;
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end] && (end - start <= 2 || isPal[start + 1][end - 1])) {
                    isPal[start][end] = true;
                    minCut = (start == 0) ? 0 : min(minCut, dp[start - 1] + 1);
                }
            }
            dp[end] = minCut;
        }

        return dp[n - 1];
    }
};
