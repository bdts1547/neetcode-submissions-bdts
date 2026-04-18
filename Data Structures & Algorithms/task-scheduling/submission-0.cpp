class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> hm;
        for (auto& task: tasks) {
            hm[task]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto& p: hm) {
            maxHeap.push({p.second, p.first});
        }

        int res = 0;
        while (!maxHeap.empty()) {
            vector<pair<int,char>> tmp;
            int k = n;
            while (k-->=0) {
                res++;
                if (!maxHeap.empty()) {
                    auto p = maxHeap.top();
                    maxHeap.pop();
                    p.first--;
                    if (p.first > 0) {
                        tmp.push_back({p.first, p.second});
                    }
                } 

                if (maxHeap.empty() && tmp.empty()) break;
            }


            for (auto& p: tmp) {
                maxHeap.push({p.first, p.second});
            }

        }

        return res;
    }
};
