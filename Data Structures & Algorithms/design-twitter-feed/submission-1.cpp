class Twitter {
    int time;
    unordered_map<int,unordered_set<int>> follow_map;
    unordered_map<int,vector<pair<int,int>>> tweet_map;
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet_map[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> res=tweet_map[userId];
        for(auto followee:follow_map[userId])
        {
            res.insert(res.end(),tweet_map[followee].begin(),tweet_map[followee].end());
        }
        sort(res.rbegin(),res.rend());
        vector<int> result;
        if(res.size()<10)
        {
            for(auto i:res)
            {
                result.push_back(i.second);
            }
        }else{
            for(auto i=0;i<10;i++)
            {
                result.push_back(res[i].second);
            }

        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
if(followerId!=followeeId)  follow_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
    if(followerId!=followeeId)    follow_map[followerId].erase(followeeId);
    }
};
