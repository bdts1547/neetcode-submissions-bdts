class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        vector<int> subset;
        backtracking(nums, 0, subset, res);
        return res;
    }

    void backtracking(const vector<int>& nums, int k, vector<int>& subset, int& res) {
        if (k >= nums.size()) {
            res += xorArray(subset);
            int tmp = subset[0];
            for (auto& n : subset) {
                printf("%d ", n);
            }
            printf("t = %d  \n", xorArray(subset));
            return;
        }

        subset.push_back(nums[k]); // 0-3 1-1 2-1
        backtracking(nums, k + 1, subset, res);

        subset.pop_back();
        backtracking(nums, k + 1, subset, res);
       
    }

    int xorArray(vector<int> nums) {
        if (nums.empty()) return 0;
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res ^=  nums[i];
        }
        return res;
    }
};