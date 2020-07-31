class Solution {
public:
    int rob(vector<int>& nums) {
        int answer;
        int size = nums.size();
        int dp[401];

        if (size == 0)
            return 0;
        else if (size == 1)
            return nums[0];
        else if (size == 2)
            return ((nums[0] > nums[1]) ? nums[0] : nums[1]);
        else
        {
            dp[0] = nums[0];
            dp[1] = nums[1];
            dp[2] = nums[0] + nums[2];
        }

        for (int i = 3; i < size; i++)
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
        answer = max(dp[size - 1], dp[size - 2]);
       
        return answer;
    }
};
