class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(0, nums, target, 0, subset, res);
        return res;
    }

    void dfs(int k, const vector<int>& nums, const int target, int sum, vector<int>& subset, vector<vector<int>>& res) {
        if (k >= nums.size()) return;
        if (target == sum) {
            res.push_back(subset);
            return;
        }

        for (int i = k; i < nums.size(); i++) {
            if (sum + nums[i] <= target) {
                subset.push_back(nums[i]);
                dfs(i, nums, target, sum + nums[i], subset, res);
                subset.pop_back();
            }
        }

        

        
        // printf("\nEnd\n");
    }



};
