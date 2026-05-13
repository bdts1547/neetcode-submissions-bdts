class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sub;
        backtracking(1, n, k, sub, res);
        return res;
    }

    void backtracking(int i, int n, int k, vector<int>& subset, vector<vector<int>>& res) {
        if (k == subset.size()) {
            res.push_back(subset);
            return;
        }

        for (int j = i; j <= n; j++) {
            subset.push_back(j);
            backtracking(j+1, n, k, subset, res);
            subset.pop_back();
        }
    }
};