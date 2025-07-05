class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms = -10000;
        int cs = -10000;
        for(int i = 0;i<nums.size();i++){
            cs = max(cs+nums[i],nums[i]);
            ms = max(ms,cs);
        }
        return ms;
    }
};