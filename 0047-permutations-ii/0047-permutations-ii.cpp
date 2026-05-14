class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> subset;
        vector<bool> visited (nums.size(), false);
        backtracking(0, nums, visited, subset, res);
        return vector<vector<int>> (res.begin(), res.end());
    }

    void backtracking(int i, const vector<int>& nums, vector<bool>& visited,
    vector<int>& subset, set<vector<int>>& res) {
        if (subset.size() == nums.size()) {
            res.insert(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
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