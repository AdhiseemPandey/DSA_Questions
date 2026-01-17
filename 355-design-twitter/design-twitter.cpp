// PRE METHOD 
// class Twitter {
// public:
//     map<int, set<int>> friends;
//     int curr=0;
//     priority_queue<vector<int>>timeline;
//     Twitter() {
//         friends.clear();
//         curr = 0;
//         timeline = priority_queue<vector<int>>();
//     }
    
//     void postTweet(int userId, int tweetId) {
//         timeline.push({curr++, tweetId, userId});
//     }
    
//     vector<int> getNewsFeed(int userId) {
//         vector<int>ans;
//         priority_queue<vector<int>> userTimeline=timeline;
//         int n = 0;
//         while(!userTimeline.empty() && n < 10) {
//             auto topTweet = userTimeline.top();
//             userTimeline.pop(); 
//             if(topTweet[2] == userId || friends[userId].count(topTweet[2])){
//                 ans.push_back(topTweet[1]);
//                 n++;
//             }
//         }
//         return ans;
//     }


// FOR TLE REMOVAL CODE -> as I am copying timeline in userTimeLine => O ( n log n )
class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int,int>>> tweets; // user -> {time, tweetId}
    unordered_map<int, unordered_set<int>> followees; // user -> set of followees

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // max heap by time
        priority_queue<pair<int,int>> pq;

        // include user's own tweets
        for (auto &t : tweets[userId]) pq.push(t);

        // include followees' tweets
        for (int f : followees[userId]) {
            for (auto &t : tweets[f]) pq.push(t);
        }

        vector<int> ans;
        int count = 0;
        while (!pq.empty() && count < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

    
//     void follow(int followerId, int followeeId) {
//         friends[followerId].insert(followeeId);
//     }
    
//     void unfollow(int followerId, int followeeId) {
//         friends[followerId].erase(followeeId);
//     }
// };
 

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */