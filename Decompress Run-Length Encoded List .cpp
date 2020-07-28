class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        int freq, val;
        for (int i = 0; i < size / 2; i++)
        {
            freq = nums[2 * i];
            val = nums[2 * i + 1];
            for (int j = 0; j < freq; j++)
                ans.push_back(val);
        }
        return ans;
    }
};