class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double, vector<int>>> maxHeap;

        for (auto& p: points) {
            double distance = sqrt(pow(p[0], 2) + pow(p[1], 2));
            // printf("%0.2f %d %d\n ", distance, p[0], p[1]);
            maxHeap.push({distance, p});
            if (maxHeap.size() > k) {
                // printf("%0.2f\n", maxHeap.top().first);
                maxHeap.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            // printf("%0.2f\n", maxHeap.top().first);

            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
