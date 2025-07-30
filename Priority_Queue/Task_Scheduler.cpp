#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int leastInterval(vector<char>& tasks, int k) 
{
    int n = tasks.size();
    vector<int> map(26,0);
    for(auto t : tasks)
    {
        map[t - 'A']++;
    }

    priority_queue<int> pq;
    for(int i=0; i<26; i++)
    {
        if(map[i] > 0)
        pq.push(map[i]);
    }

    int time = 0;
    while(!pq.empty())
    {
        vector<int> temp;
        for(int i=1; i<=k+1; i++) // selecting k+1 tasks at a time to complete because after k+1 task, I can repeat the same task
        {
            if(!pq.empty())
            {
                int a = pq.top();
                pq.pop();
                temp.push_back(a-1);
            }
        }

        for(int i=0; i<temp.size(); i++)
        {
            if(temp[i] > 0)
            pq.push(temp[i]);
        }

        if(pq.empty())
        time += temp.size();
        else 
        time += k+1;
    }
    return time;
}

int main()
{
	
	return 0;
}

// Time Complexity - O(26*N)
// Space Complexity - O(N)

// Approach - Taking n+1 task at a time from priority queue and putting them back by reducing their frequencies 