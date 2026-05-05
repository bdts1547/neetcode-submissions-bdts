class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        backtracking(0, candidates, target, 0, subset, res);
        return res;
    }

    void backtracking(int k, const vector<int>& candidates, const int target, int acc,
    vector<int>& subset, vector<vector<int>>& res) {
        // if (k >= candidates.size()) return;
        if (target == acc) {
            res.push_back(subset);
            return;
        }

        for (int i = k; i < candidates.size(); i++) {
            int temp = candidates[i];
            if (i > k && candidates[i] == candidates[i-1]) continue;
            if (acc + temp > target) break;
            subset.push_back(temp);
            backtracking(i + 1, candidates, target, acc + temp, subset, res);
            subset.pop_back();
            } 
    }
};
