class Solution {
public:
    bool checkAllIsZero (vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) return false;
        }
        return true;
    }

    void subtract(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) nums[i] -= k;
        }
    }

    int minimumOperations(vector<int>& nums) {
        int answer = 0;
        while (!checkAllIsZero(nums)) {
            priority_queue<int, vector<int>, greater<int>> pq;
            for (auto& num : nums) {
                if (num > 0) pq.push(num);
            }
            
            int min_val = pq.top();
            pq.pop();
            subtract(nums, min_val);
            answer++;
        }

        return answer;
    }
};
