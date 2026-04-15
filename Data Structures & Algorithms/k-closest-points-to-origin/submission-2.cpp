class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> maxHeap;

        int i = 0;
        for (auto& p: points) {
            int distance = (pow(p[0], 2) + pow(p[1], 2));
            maxHeap.push({distance, i++});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty()) {
            int idx = maxHeap.top().second;
            res.push_back(points[idx]);
            maxHeap.pop();
        }
        return res;
    }
};
