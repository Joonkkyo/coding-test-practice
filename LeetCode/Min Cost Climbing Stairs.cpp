class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int* dp = new int[size + 1];
        int answer;
        dp[0] = cost[0];
        dp[1] = cost[1];

        if (size == 2)
            return min(dp[0], dp[1]);

        for (int i = 2; i < size; i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];

        return (min(dp[size - 1], dp[size - 2]));
    }
};