#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long time;
unordered_map<int,set<int>> following;
unordered_map<int,vector<pair<int,int>>>tweets;

Twitter() {
	time = 0;
}

void postTweet(int userId, int tweetId) {
	tweets[userId].push_back({++time,tweetId});
}

vector<int> getNewsFeed(int userId) {
	vector<int> ans;
	priority_queue<pair<int,int>> pq;
	for(auto it : tweets[userId]) // checking his own tweets
		pq.push(it);
	for(auto it : following[userId]) // checking tweets of his followee
	{
		for(auto i : tweets[it])
			pq.push(i);
	}
	int n = 10;
	while(!pq.empty() && n--) 
	{
		ans.push_back(pq.top().second);
		pq.pop();
	}
	return ans;
}

void follow(int followerId, int followeeId) {
	following[followerId].insert(followeeId);
}

void unfollow(int followerId, int followeeId) {
	following[followerId].erase(followeeId);
}

int main()
{
	
	return 0;
}