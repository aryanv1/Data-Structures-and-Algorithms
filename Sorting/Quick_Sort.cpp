#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Divide and Conquer Algorithm
// Time Complexity - O(NLogN), Space Complexity - O(1) -> except recursion stack space
int partition (int arr[], int low, int high)
{
	int pivot = low;
	int i = low, j = high;
	while(i < j)
	{
		while(arr[i] <= arr[pivot] && i <= high-1) // keeping equal elements to the left side 
		{
			i++;
		}
		while(arr[j] > arr[pivot] && j >= low+1)
		{
			j--;
		}
		if(i < j)
			swap(arr[i],arr[j]);
	}
	swap(arr[j],arr[pivot]);
	return j;
}

void quickSort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pInd = partition(arr,low,high);
		quickSort(arr,low,pInd-1);
		quickSort(arr,pInd+1,high);
	}
}

int main()
{
	
	return 0;
}