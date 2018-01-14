class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter(): time(0) {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (userTweets.find(userId) == userTweets.end())
            follow(userId, userId);
            
        userTweets[userId].emplace_back(tweetId, time++);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](Tid l, Tid r) { return l.first[l.second].second < r.first[r.second].second; };
        priority_queue<Tid, vector<Tid>, TidComparator> pq;
        
        const auto & followees = userFollows[userId];
        for (auto user : followees) {
            auto & tweets = userTweets[user];
            if (!tweets.empty())
                pq.emplace(&tweets, tweets.size() - 1);
        }
        
        vector<int> ans;
        for (int k = 0; k < 10 && !pq.empty(); k++) {
            Tid tid = pq.top();
            pq.pop();
            ans.push_back((*tid.first)[tid.second--].first);
            if (tid.second >= 0) {
                pq.push(tid);
            }
        }
        
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        userFollows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            userFollows[followerId].erase(followeeId);
    }
    
private:
    typedef pair<int, int> Tweet; // tweetId, time
    typedef pair<vector<Tweet>*, int> Tid;
    struct TidComparator {
        bool operator()(const Tid& l, const Tid& r) {
            return (*l.first)[l.second].second < (*r.first)[r.second].second;
        }
    };
    
    unordered_map<int, vector<Tweet>> userTweets; // userId, tweets
    unordered_map<int, unordered_set<int>> userFollows; // userId, follows
    int time;
};

/**
 *  * Your Twitter object will be instantiated and called as such:
 *   * Twitter obj = new Twitter();
 *    * obj.postTweet(userId,tweetId);
 *     * vector<int> param_2 = obj.getNewsFeed(userId);
 *      * obj.follow(followerId,followeeId);
 *       * obj.unfollow(followerId,followeeId);
 *        */
