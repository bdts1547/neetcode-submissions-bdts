class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subset;
        unordered_map<char,int> hm;
        backtracking(n, hm, subset, res);
        return res;
    }

    void backtracking(int n, unordered_map<char,int>& hm, string& subset, vector<string>& res) {
        if (hm[')'] > hm['(']) return; // pruning

        if (hm['('] == n && hm['('] == hm[')']) {
            res.push_back(subset);
            return;
        }

        if (hm['('] < n) {
            subset.push_back('(');
            hm['(']++;
            backtracking(n, hm, subset, res);
            subset.pop_back();
            hm['(']--;
        }


        if (hm[')'] < hm['(']) {
            subset.push_back(')');
            hm[')']++;
            backtracking(n, hm, subset, res);
            subset.pop_back();
            hm[')']--;
        }
    }
};