#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Brute Force - From evry index we will go left and right and find the max height on both sides
// and then we will find the min of both and then we will subtract the current height from it and add it to our ans.
// Time Complexity - O(N^2), Space Complexity - O(1)
int trap(vector<int> &arr)
{
    int n = arr.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0)
        {
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while (j < n)
        {
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
}

// Better Approach
// We will use two arrays to store the left max and right max for each index
// Time Complexity - O(N), Space Complexity - O(2*N)
int trap(vector<int> &arr)
{
    int n = arr.size();
    int prefix[n], suffix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }
    return waterTrapped;
}

// Optimal Approach
// We will use two pointers to traverse the array from both ends
// Time Complexity - O(N), Space Complexity - O(1)
int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;
    int res = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
                maxLeft = height[left];
            else
                res += maxLeft - height[left];
            left++;
        }
        else
        {
            if (height[right] >= maxRight)
                maxRight = height[right];
            else
                res += maxRight - height[right];
            right--;
        }
    }
    return res;
}

int main()
{

    return 0;
}