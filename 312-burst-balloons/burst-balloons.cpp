class Solution {
public:
    int dp[305][305];

    int helper(vector<int>& nums, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int maxCoins = 0;
        for (int k = i; k <= j; ++k) {
            int gain = nums[i - 1] * nums[k] * nums[j + 1];
            int left = helper(nums, i, k - 1);
            int right = helper(nums, k + 1, j);
            maxCoins = max(maxCoins, left + gain + right);
        }
        return dp[i][j] = maxCoins;
    }

    int maxCoins(vector<int>& originalNums) {
        vector<int> nums;
        nums.push_back(1);
        for (int num : originalNums) nums.push_back(num);
        nums.push_back(1);

        memset(dp, -1, sizeof(dp));
        int n = originalNums.size();
        return helper(nums, 1, n);
    }
};
