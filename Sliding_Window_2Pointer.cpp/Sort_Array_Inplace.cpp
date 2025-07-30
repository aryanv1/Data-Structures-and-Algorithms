#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void Solution::merge(vector<int> &A, vector<int> &B) 
{
	int m = A.size();
	int n = B.size();

    // Resize A to accommodate elements from both A and B
	A.resize(m + n);

    // Indices for the last elements in A, B, and the merged vector
    int i = m - 1;  // Last element of the original A
    int j = n - 1;  // Last element of B
    int k = m + n - 1;  // Last position of the resized A

    // Merge A and B, starting from the end
    while (i >= 0 && j >= 0) 
    {
    	if (A[i] > B[j]) 
    	{
    		A[k] = A[i];
    		i--;
    	} 
    	else 
    	{
    		A[k] = B[j];
    		j--;
    	}
    	k--;
    }

    // Copy remaining elements of B (if any)
    while (j >= 0) 
    {
    	A[k] = B[j];
    	j--;
    	k--;
    }
}

int main()
{

	return 0;
}