class Twitter {
private:
    struct tweet{
        int userId; 
        int tweetId;
    };

    list<tweet> tweets{};
    unordered_map<int, unordered_set<int>> users{};

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        users[userId];
        tweets.push_back(tweet{userId, tweetId});    
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed{};
        bool user = users.contains(userId);
        for(auto tw = tweets.rbegin(); tw != tweets.rend(); ++tw){
            if(!user || userId == tw->userId || users[userId].contains(tw->userId)){
                feed.push_back(tw->tweetId);
                if(feed.size() == 10) return feed;
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */