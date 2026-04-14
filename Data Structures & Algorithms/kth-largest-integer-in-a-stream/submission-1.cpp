class KthLargest {
public:
    // MIN HEAP
    priority_queue<int, vector<int>, greater<int>> heap;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for (auto num: nums) {
            heap.push(num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > cap) {
            heap.pop();
        }
        return heap.top();
    }
};
