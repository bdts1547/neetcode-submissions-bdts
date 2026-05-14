class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        vector<int> subset;
        backtracking(0, nums, subset, res);
        // return res;
        return vector<vector<int>> (res.begin(), res.end());
    }

    void backtracking(int k, const vector<int>& nums, vector<int>& subset, 
    set<vector<int>>& res) {
        if (k >= nums.size()) {
            res.insert(subset);
            return;
        }

        // add
        subset.push_back(nums[k]);
        backtracking(k+1, nums, subset, res);

        // remove
        subset.pop_back();
        backtracking(k+1, nums, subset, res);
    }
};
