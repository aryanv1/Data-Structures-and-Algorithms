#include <bits/stdc++.h>
using namespace std;
#define ll long long int

priority_queue<int> maxHeap;
priority_queue<int,vector<int>,greater<int>> minHeap;
MedianFinder() {

}
// For n -> odd, MaxHeap will have odd number of elements(1 element more than MinHeap) and for even both will have same even number of elements
// Distributing such that top of MaxHeap will be our median since in MaxHeap all elements other than top will be smaller than top and elements in MinHeap will be greater than top
// For even we'll have average of top of both Heaps
void addNum(int num) {
	if(maxHeap.empty() || maxHeap.top() >= num)
		maxHeap.push(num);
	else
		minHeap.push(num);
    // because for the case of odd maxHeap have 1 element more
	if(maxHeap.size() > minHeap.size() + 1)
	{
		minHeap.push(maxHeap.top());
		maxHeap.pop();
	}
	else if(maxHeap.size() < minHeap.size())
	{
		maxHeap.push(minHeap.top());
		minHeap.pop();
	}
}

double findMedian() {
    // even number of elements
	if(maxHeap.size() == minHeap.size())
	{
		double a = maxHeap.top();
		double b = minHeap.top();
		return (a + b)/2.0;
	}
    // odd number of elements
	return maxHeap.top();
}

int main()
{
	
	return 0;
}

// Time Complexity - O(logN)
// Space Complexity - O(1) -> Not considering data stream

// Here basically we are having two buckets one will have all elements lesser than equal to median(left - MaxHeap) and right bucket will have elements greater than median(right - MinHeap)