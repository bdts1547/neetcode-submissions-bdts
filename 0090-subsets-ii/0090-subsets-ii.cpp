class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        vector<int> subset;
        dfs(0, nums, subset, res);
        return vector<vector<int>> (res.begin(), res.end());
    }

    void dfs(int i, const vector<int>& nums, vector<int>& subset, set<vector<int>>& res) {
        if (i >= nums.size()) {
            res.insert(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(i+1, nums, subset, res);

        subset.pop_back();
        dfs(i+1, nums, subset, res);

    }
};