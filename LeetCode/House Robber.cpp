class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int* dp = new int[size + 1];
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < size; i++)
        {
            dp[i] = max(dp[i], dp[i - 2]) + nums[i];
        }
        return max(dp[size - 1], dp[size - 2]);
    }
};