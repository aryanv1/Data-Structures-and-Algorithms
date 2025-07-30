#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Heap {

private:
	int size;
	vector<int> arr;

public:
	Heap(int n)
	{	
		size = 0; // Always pointing to last element inserted
		arr = vector<int>(n); // Maximum size of heap
	}
	void heapify(int i)
	{
		int largest = i;
		int left = 2*i;
		int right = 2*i + 1;

		// If left child is larger than largest
		if(left <= size && arr[left] > arr[largest])
			largest = left;
		// If right child is larger then maybe *updated largest
		if(right <= size && arr[right] > arr[largest])
			largest = right;

		if(largest != i)
		{
			swap(arr[largest],arr[i]);
			heapify(largest);
		}
	}
	// Time Complexity - O(LogN)
	void insert(int val)
	{
		size++; // having 1 based indexing
		int ind = size;
		arr[ind] = val;
		int parent = ind/2; // parent of any node (0-based -> (ind-1)/2)
		while(ind > 1 && arr[parent] < arr[ind])
		{
			swap(arr[ind],arr[parent]);
			ind = parent;
			parent = ind/2;
		}
	}
	// Time Complexity - O(LogN)
	void deleteNode()
	{
		arr[1] = arr[size]; // Put last element at first index
		size--; // Indirectly deleting top element
		heapify(1); // Perform heapify from 1st Index
	}
	vector<int> heapSort()
	{
		// Build heap (rearrange array) -> already done
	    // for (int i = size / 2 - 1; i >= 0; i--)
	    //     heapify(i);

		vector<int> ans; // Can also be ignored since the array arr will also be same as this one
		while(size > 0)
		{
			swap(arr[size],arr[1]);
			ans.push_back(arr[size]); // greater element will go at last
			size--;
			heapify(1);
		}
		return ans;
	}
	void print()
	{
		for(int i=1; i<=size; i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
// Elements after size/2 till end will be leaf elements

int main()
{
	Heap h(100);
	h.insert(52);
	h.insert(46);
	h.insert(47);
	h.insert(43);
	h.insert(42);
	h.print();
	h.deleteNode();
	h.print();
	vector<int> ans = h.heapSort(); // maxHeap -> descending and minHeap -> ascending
	for(int i=0; i<ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

// How can we delete a Key from inbetween of array?
// Ans: If it is minHeap then make that key INT_MIN else INT_MAX
// then just do as we have done in insert function i.e, moving up by swaping
// after that this INT_MIN/INT_MAX will be at top and then simply delete the top element