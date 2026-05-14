class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> subset;
        vector<bool> visited (nums.size(), false);

        // for (int i = 0; i < nums.size(); i++) {
        //     visited[i] = true;
        //     subset.push_back(nums[i]);
        //     for (int j = 0; j < nums.size(); j++) {
        //         if (!visited[j]) {
        //             subset.push_back(nums[j]);
        //         }
        //     }
        //     res.push_back(subset);
        //     subset.clear();
        //     visited[i] = false;
        // }

        backtracking(0, nums, visited, subset, res);
        return vector<vector<int>> (res.begin(), res.end());
    }

    void backtracking(int k,const vector<int>& nums, vector<bool>& visited,
    vector<int>& subset, set<vector<int>>& res) {
        if (subset.size() >= nums.size()) {
            res.insert(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                subset.push_back(nums[i]);
                backtracking(i + 1, nums, visited, subset, res);
                subset.pop_back();
                visited[i] = false;
            }
        }
    }
};