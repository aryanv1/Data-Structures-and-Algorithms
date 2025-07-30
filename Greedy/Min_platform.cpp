#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// We just require time and not pair of both starting and ending time
int findPlatform(int arr[], int dep[], int n)
{
    // 	int maxi = 1;
    // 	vector<pair<int,char>> v;
    // 	for(int i=0; i<n; i++)
    // 	{
    // 	    v.push_back({arr[i],'A'});
    // 	    v.push_back({dep[i],'D'});
    // 	}
    // 	sort(v.begin(),v.end());
    // 	int cnt = 0;
    // 	for(int i=0; i<2*n; i++)
    // 	{
    // 	    if(v[i].second == 'A')
    // 	    cnt++;
    // 	    else cnt--;
    // 	    maxi = max(maxi,cnt);
    // 	}
    // 	return maxi;

    // another way
	sort(arr,arr+n);
	sort(dep,dep+n);
	int i=0,j=0;
	int cnt = 0;
	int maxi = 1;	
	while(i < n)
	{
		if(arr[i] < dep[j])
		{
			cnt++;
			i++;
		}
		else
		{
			cnt--;
			j++;
		}
		maxi = max(cnt,maxi);
	}
	return cnt;
}
int main()
{
	
	return 0;
}

// Here we have to see the time for arrival and departure both separetely because we just need to see how many consecutive trains are arriving -> if inbetween any train departs then reduce the count