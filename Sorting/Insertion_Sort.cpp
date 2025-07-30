#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// While going through each index check whether array till that index is sorted or not
// If not sorted sort it by swaping
// Time Complexity - O(N^2), Space Compexity - O(1)
// Best Case Time Complexity - O(N) -> when whole array is sorted inner loop will not be executed
void Iterative_Insertion_Sort(int arr[], int n)
{
	for(int i=1; i<n; i++)
	{
		int j = i;
		while(j>0 && arr[j] < arr[j-1])
		{
			swap(arr[j],arr[j-1]);
			j--;
		}
	}
}

// Time Complexity - O(N^2), Space Complexity - O(N)
void Recursive_Insertion_Sort(int arr[], int i, int n) // call -> (arr,1,n)
{

    // Base Case: i == n.
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) 
    {
        swap(arr[j - 1], arr[j]);
        j--;
    }

    Recursive_Insertion_Sort(arr, i + 1, n);
}

int main()
{
	
	return 0;
}