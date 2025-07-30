#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
public:
	static bool compare(Item i1 , Item i2){
		double a1 = (double(i1.value) / double(i1.weight));
		double a2 = (double(i2.value) / double(i2.weight));
		return a1>a2;
	}

	double fractionalKnapsack(int W, Item arr[], int n)
	{
		sort(arr,arr+n,compare);
		double ans = 0;
		int i = 0;
		int index = -1;
		while(i < n){
			if(W == 0){
				break;
			}
			if(W < arr[i].weight){
				index = i;
				break;
			}
			ans += (arr[i].value);
			W -= arr[i].weight;
			i++;
		}

		if(index != -1){
			ans += ((double(arr[index].value) / double(arr[index].weight))*W);
		}
		return ans;
	}
};
int main()
{

	return 0;
}