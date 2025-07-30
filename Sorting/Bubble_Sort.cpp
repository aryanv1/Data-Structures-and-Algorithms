#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Go from 0 to n-1, then n-2, n-3 ... 1
// Keep on dwapping i and i+1 elements
// Every time maximum element will move to last
// Time Complexity - O(N^2), Space Complexity - O(1)
// Best Case Time Complexity - O(N) -> When array is already sorted
void Iterative_Bubble_Sort(int arr[], int n)
{
	for(int i=n-1; i>0; i--)
	{
		int didSwap = 0;
		for(int j=0; j<i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				didSwap = 1; 
			}
		}
		if(didSwap == 0) // Indicating array is already sorted
			break;
	}
}

// Time Complexity - O(N^2), Space Complexity - O(N)
void Recursive_Bubble_Sort(int arr[], int n) 
{
    // Base Case: range == 1.
    if (n == 1) return;

    int didSwap = 0;
    for (int j = 0; j < n - 1; j++) 
    {
        if (arr[j] > arr[j + 1]) 
        {
            swap(arr[j], arr[j + 1]);
            didSwap = 1;
        }
    }

    // if no swapping happens.
    if (didSwap == 0) return;

    //Range reduced after recursion:
    Recursive_Bubble_Sort(arr, n - 1);
}

int main()
{
	
	return 0;
}