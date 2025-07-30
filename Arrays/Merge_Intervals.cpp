#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute Force - O(nlogn + 2n)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// Time Complexity - O(nlogn + n) - Optimal
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    pair<int,int> p = {intervals[0][0],intervals[0][1]};
    vector<vector<int>> ans;
    for(int i=1; i<n; i++)
    {
        if(intervals[i][0] <= p.second)
        {
            p.first = min(p.first,intervals[i][0]);
            p.second = max(p.second,intervals[i][1]);
        }
        else
        {
            ans.push_back({p.first,p.second});
            p.first = intervals[i][0];
            p.second = intervals[i][1];
        }
    }
    ans.push_back({p.first,p.second});
    return ans;
}

int main()
{
	
	return 0;
}