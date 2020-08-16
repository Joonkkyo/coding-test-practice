class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        int flag = 0;
        bool answer;
        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                if (i > 0)
                {
                    if (nums[i - 1] <= nums[i + 1])
                        nums[i] = nums[i - 1];
                    else
                        nums[i + 1] = nums[i];
                    break;
                }
                else
                {
                    nums[i] = nums[i + 1];
                    break;
                }
            }
        }

        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                answer = false;
                break;
            }
            else
                answer = true;
        }

        return answer;
    }
};