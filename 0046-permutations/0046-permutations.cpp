class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> visited(nums.size(), false);
        vector<int> perm;
        backtracking(nums, perm, visited, res);
        return res;
    }

    void backtracking(const vector<int>& nums, vector<int>& perm, vector<int>& visited, 
    vector<vector<int>>& res) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                perm.push_back(nums[i]);
                backtracking(nums, perm, visited, res);
                perm.pop_back();
                visited[i] = false;
            }
        }
    }
};