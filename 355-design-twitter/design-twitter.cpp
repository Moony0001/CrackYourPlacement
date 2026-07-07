class Twitter {
public:
    struct Tweet{
        int tweetId;
        int time;
    };

    struct FeedNode{
        int tweetId;
        int userId;
        int time;
        int index;
    };

    struct CompareTweet{
        bool operator()(const FeedNode& a, const FeedNode& b){
            return a.time < b.time;
        }
    };

    vector<unordered_set<int>> follows;
    vector<vector<Tweet>> userTweets;
    int globaltime;

    Twitter() {
        follows.resize(501);
        userTweets.resize(501);
        globaltime = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        Tweet t = {tweetId, globaltime};
        userTweets[userId].push_back(t);
        globaltime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        priority_queue<FeedNode, vector<FeedNode>, CompareTweet> pq;

        follows[userId].insert(userId);

        for(int f : follows[userId]){
            int size = userTweets[f].size();
            if(size>0){
                Tweet latest = userTweets[f][size-1];
                pq.push({latest.tweetId, f, latest.time, size-1});
            }
        }

        while(!pq.empty() && ans.size()<10){
            FeedNode top = pq.top();
            pq.pop();
            ans.push_back(top.tweetId);

            if(top.index>0){
                int ind = top.index-1;
                Tweet nextTweet = userTweets[top.userId][ind];
                pq.push({nextTweet.tweetId, top.userId, nextTweet.time, ind});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            follows[followerId].erase(followeeId);
        }
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