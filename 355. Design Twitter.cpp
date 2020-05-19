bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
class Twitter {
private:
    map<int,vector<pair<int,long>>> t;
    map<int,set<int>> f;
    long id=0;
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto it=t.find(userId);
        if(it==t.end()){
            vector<pair<int,long>> tmp={{tweetId, id}};
            t.insert({userId, tmp});
        }else{
            it->second.push_back({tweetId, id});
        }
        id++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto it_f=f.find(userId);
        set<int> users;
        if(it_f!=f.end()) users=it_f->second;
        users.insert(userId);
        vector<pair<int,long>> all_tweets;
        for(int user:users){
            // cout<<user<<endl;
            auto it_t=t.find(user);
            if(it_t==t.end()) continue;
            auto tweets=it_t->second;
            for(int i=tweets.size()-1,j=0;i>=0&&j<10;i--,j++){
                all_tweets.push_back(tweets[i]);
            }
        }
        sort(all_tweets.begin(), all_tweets.end(), sortbysec);
        vector<int> ret;
        for(int i=all_tweets.size()-1,j=0;i>=0&&j<10;i--,j++){
            ret.push_back(all_tweets[i].first);
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        auto it=f.find(followerId);
        if(it==f.end()){
            set<int> tmp={followeeId};
            f.insert({followerId, tmp});
        }else{
            it->second.insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto it=f.find(followerId);
        if(it!=f.end()){
            it->second.erase(followeeId);
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