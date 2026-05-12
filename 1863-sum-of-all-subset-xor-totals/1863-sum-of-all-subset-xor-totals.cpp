class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return backtracking(nums, 0, 0);
    }

    int  backtracking(const vector<int>& nums, int k, int total) {
        if (k == nums.size()) {
            return total;
        }

        return backtracking(nums, k + 1, nums[k] ^ total) + backtracking(nums, k + 1, total);
       
    }

};