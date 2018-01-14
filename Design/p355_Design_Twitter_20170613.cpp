#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
    
struct Tweet {
    static int glb_time;
    int t = -1;
    int id = -1;
    Tweet* next = nullptr;
    
    Tweet(int i, Tweet* n) : id{i}, next{n} {
        t = ++glb_time;
    }
    
    bool operator <(const Tweet& b) const {
        return t < b.t;
    }
};

int Tweet::glb_time = 0;

class TweetPtrComparator {
public:
    bool operator ()(Tweet* a, Tweet* b) {
        return *a < *b;
    }
};

class User {
public:
    string ToString() {
        ostringstream os;
        os << "{";
        for (Tweet* i = news_; i != nullptr; i = i->next)
            os << i->id << " ";
        os << "}";
        return os.str();
    }
    
    void Tweets(int tweetId) {
        auto tw = new Tweet(tweetId, news_);
        news_ = tw;
    }
    
    vector<int> GetNewsFeed() {
        auto cmp = [](Tweet* a, Tweet* b) {return *a < *b;};
        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> pq(cmp);
        //priority_queue<Tweet*, vector<Tweet*>, TweetPtrComparator> pq;
        if (news_ != nullptr) {
            pq.push(news_);
            }

        for (auto f : followees_)
            if (f->news_ != nullptr)
                pq.push(f->news_);
        
        vector<int> ans;
        for (int k = 0; k < 10 && !pq.empty(); k++) {
            auto tw = pq.top();
            pq.pop();
            ans.push_back(tw->id);
            if (tw->next)
                pq.push(tw->next);
        }
        
        return ans;
    }
    
    void AddFollowee(User* u) {
        followees_.insert(u);
    }
    
    void RmFollowee(User* u) {
        followees_.erase(u);
    }
    
    Tweet* news_{nullptr};

private:
    unordered_set<User*> followees_;
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    User* GetUser(int userId) {
        if (users.find(userId) == users.end()) {
            users[userId] = new User();
        }
        
        return users[userId];
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        GetUser(userId)->Tweets(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        return GetUser(userId)->GetNewsFeed();
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        GetUser(followerId)->AddFollowee(GetUser(followeeId));
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        GetUser(followerId)->RmFollowee(GetUser(followeeId));
    }
    
private:
    unordered_map<int, User*> users;

};

/**
 *  * Your Twitter object will be instantiated and called as such:
 *   * Twitter obj = new Twitter();
 *    * obj.postTweet(userId,tweetId);
 *     * vector<int> param_2 = obj.getNewsFeed(userId);
 *      * obj.follow(followerId,followeeId);
 *       * obj.unfollow(followerId,followeeId);
 *        */

ostream& operator <<(ostream& os, const vector<int>& vec) {
    os << "[";
    for (auto i : vec)
        os << i << "  ";
    os << "]";
    return os;
}

int main(int argc, char* argv[]) {
    Twitter obj{};
    obj.postTweet(1, 9);
    vector<int> ans = obj.getNewsFeed(1);
    cout << "NewsFeed of " << 1 << " = " << ans << endl;
    
    obj.postTweet(2, 8);
    obj.follow(1, 2);
    cout << "NewsFeed of " << 1 << " = " << obj.getNewsFeed(1) << endl;

    obj.unfollow(1, 2);
    cout << "NewsFeed of " << 1 << " = " << obj.getNewsFeed(1) << endl;
    
    return 0;
}
