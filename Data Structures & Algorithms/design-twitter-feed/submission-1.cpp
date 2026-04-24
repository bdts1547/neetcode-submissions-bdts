class Twitter {
public:
    unordered_map<int, unordered_set<int>> followMap; // userId - followers
    unordered_map<int, vector<pair<int, int>>> tweetMap; // userId - arr[<count, tweetId>]
    int count;

    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId);
        vector<pair<int,int>> store;
        // for (auto& p: tweetMap[userId]) {
        //     printf("%d\n", p.second);

        //     store.push_back(p);
        // }
        
        for (auto& id: followMap[userId]) {
            for (auto& p: tweetMap[id]) {
                printf("%d\n ", p.second);
                store.push_back(p);
            }
        }

        sort(store.rbegin(), store.rend());
        vector<int> res;
        int post = store.size() < 10 ? store.size() : 10;
        for (int i = 0; i < post; i++) {
            res.push_back(store[i].second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
