class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (auto& stone: stones) {
            maxHeap.push(stone);
        }

        int x, y;
        while (maxHeap.size() > 1) {
            x = maxHeap.top();
            maxHeap.pop();
            y = maxHeap.top();
            maxHeap.pop();

            // printf("%d %d\n", x,y);
            maxHeap.push(x - y);
            
            

        }
        return maxHeap.top();
    }
};
