// Include the required header files
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;

// Define the twitter LRUCache
class twitter {

    // Define the required private variables
    private:
        // Define a tweet
        typedef struct tweet {
            int userId;
            int tweetId;
            int time;
            tweet(int user, int tweet, int time) {
                this->userId = user;
                this->tweetId = tweet;
                this->time = time;
            }
        }tweet;

        // Define the comparator strategy for priority queue
        class cmp {
            public:
                bool operator()(tweet* &t1, tweet* &t2) {
                    return t1->time < t2->time;
                }
        };

        int globalTime;
        unordered_map<int, set<int>> following;
        priority_queue<tweet*, vector<tweet*>, cmp> tweets;

    // Define the public constructor and methods
    public:

        // Define the class constructor
        twitter() {
            globalTime = 0;
        }
        
        // Define the postTweet method
        void postTweet(int userId, int tweetId) {
            tweets.push(new tweet(userId, tweetId, globalTime++));
        }
        
        // Define the getFeed method
        vector<int> getFeed(int userId) {
            vector<int> news;
            stack<tweet*> temp;
            bool follows = (following.find(userId) != following.end());
            while(!tweets.empty() && news.size() < 10) {
                tweet *t = tweets.top();
                tweets.pop();
                if(t->userId == userId)
                    news.push_back(t->tweetId);
                else if(follows && find(following[userId].begin(), following[userId].end(), t->userId) != following[userId].end())
                    news.push_back(t->tweetId);
                temp.push(t);
            }
            while(!temp.empty()) {
                tweets.push(temp.top());
                temp.pop();
            }
            return news;
        }
        
        // Define the follow mwthod
        void follow(int followerId, int followeeId) {
            if(following.find(followerId) == following.end())
                following.insert({followerId, set<int>()});
            following[followerId].insert(followeeId);
            return;
        }
        
        // Define the unfollow method
        void unfollow(int followerId, int followeeId) {
            if(following.find(followerId) == following.end())
                return;
            if(find(following[followerId].begin(), following[followerId].end(), followeeId) == following[followerId].end())
                return;
            following[followerId].erase(followeeId);
            return;
        }
};

/*
Name        : process()
Description : Processes each query on the Twitter system
Arguments   : A 2D vector denoting the queries
Return      : A vector of the outputs
*/
vector<vector<int>> process(vector<vector<int>> queries) {
    
    // Initialize the required local variables
    twitter t = twitter();
    vector<vector<int>> result;

    // Process the queries
    for(auto &query : queries) {
        
        // Select the operation
        switch(query[0]) {
            case 1:t.postTweet(query[1], query[2]);
                    break;
            case 2:result.push_back(t.getFeed(query[1]));
                    break;
            case 3:t.follow(query[1], query[2]);
                    break;
            case 4:t.unfollow(query[1], query[2]);
                    break;
            default:
                    break;
        }
    }

    // Return the result
    return result;
}

/*
Name        : main()
Description : Handles I/O and calls the required subroutines
Arguments   : None
Return      : Integer 0
*/
int main() {
    
    // Open the input file and handle the exception
    ifstream input;
    input.open("Input.txt");
    if(input.fail()) {
        cerr << "Please provide the correct Input File...!!!" << endl;
        exit(0);
    }

    // Declare the required variables and read the input
    int n, op, u, v, t;
    input >> n;
    vector<vector<int>> queries(n);
    for(int i = 0; i < n; i++) {
        input >> op;
        queries[i].push_back(op);
        switch(op) {
            case 1:input >> u >> t;
                    queries[i].push_back(u);
                    queries[i].push_back(t);
                    break;
            case 2:input >> u;
                    queries[i].push_back(u);
                    break;
            case 3:input >> u >> v;
                    queries[i].push_back(u);
                    queries[i].push_back(v);
                    break;
            case 4:input >> u >> v;
                    queries[i].push_back(u);
                    queries[i].push_back(v);
                    break;
            default:
                    break;
        }
    }

    // Close the input file
    input.close();

    // Call the subroutine to process the queries
    vector<vector<int>> result = process(queries);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++) {
        if(i > 0)
            output << endl;
        for(int j = 0; j < result[i].size(); j++)
            (j == 0) ? (output << result[i][j]) : (output << ' ' << result[i][j]);
    }
    
    // Close the output file and return
    output.close();
    return 0;
}