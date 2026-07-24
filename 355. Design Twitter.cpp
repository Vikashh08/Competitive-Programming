class Twitter {
    int timer;

    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets;
    // {time, tweetId}

public:
    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>> pq;
        // {time, tweetId, userId, index}

        follows[userId].insert(userId);

        for (int user : follows[userId]) {
            if (tweets[user].empty()) continue;

            int idx = tweets[user].size() - 1;
            pq.push({
                tweets[user][idx].first,
                tweets[user][idx].second,
                user,
                idx
            });
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);

            if (idx > 0) {
                idx--;
                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId)
            follows[followerId].erase(followeeId);
    }
};