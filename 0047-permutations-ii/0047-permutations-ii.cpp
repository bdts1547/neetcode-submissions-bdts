class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        vector<bool> visited (nums.size(), false);
        backtracking(0, nums, visited, subset, res);
        return res;
    }

    void backtracking(int i, const vector<int>& nums, vector<bool>& visited,
    vector<int>& subset, vector<vector<int>>& res) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && visited[i-1] && nums[i-1] == nums[i]) continue;
            if (!visited[i]) {
                subset.push_back(nums[i]);
                visited[i] = true;
                backtracking(i+1, nums, visited, subset, res);
                subset.pop_back();
                visited[i] = false;
            }
        }
    }
};