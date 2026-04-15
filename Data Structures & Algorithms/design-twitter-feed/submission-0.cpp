class Twitter {
private:
    int time;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> follows;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int,int>> pq; //maxHeap by default
        // time , tweetId , userId, index_in_user_tweets
        follows[userId].insert(userId);

        for(int followee : follows[userId]){
            auto &t = tweets[followee];
            if(!t.empty()){
                int idx = t.size() - 1;
                pq.push({t[idx].first,t[idx].second,followee,idx});
            }
        }
        vector<int> result;

        while(!pq.empty() && result.size() < 10){
            auto[time,tweetId,uid,idx]=pq.top();
            pq.pop();
            result.push_back(tweetId);

            if(idx>0){
                auto &v=tweets[uid];
                pq.push({v[idx-1].first,v[idx-1].second,uid,idx-1});
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId){
            return;
        }
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
