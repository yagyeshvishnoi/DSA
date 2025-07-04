class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //..hello
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 0;i<n+1;i++)dp[i][i] = 1;
        for(int i = 0; i<n ;i++){
            int curr = dp[i][i];
            for(int j = i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    dp[i][j] = curr+1;
                    dp[j][j] = max(dp[j][j],curr+1);
                }
            }
        }
        int maxi = dp[0][0];
        for(int i = 0;i<n+1;i++)maxi = max(maxi,dp[i][i]);
        return maxi;
    }
};