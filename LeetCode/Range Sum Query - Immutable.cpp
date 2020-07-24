class NumArray {
public:
    NumArray(vector<int>& nums) {
        sums = nums;
        for (int i = 1; i < nums.size(); i++)
            sums[i] = sums[i - 1] + nums[i];
    }

    int sumRange(int i, int j) {
        if (i == 0)
            return sums[j];
        else
            return (sums[j] - sums[i - 1]);
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */