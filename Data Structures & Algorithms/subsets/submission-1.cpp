class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (auto& num: nums) { // 1
            int size = res.size(); // 0
            for (int i = 0; i < size; i++) {
                vector<int> subset = res[i]; // {}
                subset.push_back(num); // [1]
                res.push_back(subset); // [[] {1}]
            }

        }
        return res;
    }
};
