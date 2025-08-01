#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// For brute method just iterate through hours from 1 to max_element and find the minimum answer
long long getHoursToEatAll(vector<int>&piles, int bananasPerHour)
{
	long long totalHours = 0;
	for (int i = 0; i < piles.size(); i++)
	{
		int hoursToEatPile = ceil(piles[i] / (double)bananasPerHour);
		totalHours += hoursToEatPile;
	}
	return totalHours;
}
int minEatingSpeed(vector<int>& piles, int targetHours)
{
	int low = 1, high = *(max_element(piles.begin(), piles.end()));
	int ans = -1;
    //================================================================
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		long long hoursToEatAll = getHoursToEatAll(piles, mid);

		if (hoursToEatAll <= targetHours)
		{
                ans = mid; //record the answer (this is the best we could record till curr step)
                high = mid - 1;
            }
            else low = mid + 1;
        }
    //=================================================================
    return ans;
}
int main()
{
	vector<int> piles = {3,6,7,11};
	int h = 8;
	int ans = minEatingSpeed(piles,h);
	cout<<ans<<endl;
	return 0;
}
//Time Complexity - O(n*log(max(arr[i])))