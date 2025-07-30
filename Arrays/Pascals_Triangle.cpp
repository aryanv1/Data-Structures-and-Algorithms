#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Three Variations of this problem
// 1. Given Row and Column and need to find the Element
// Ans: (row-1)C(col-1) -> Combination
// Logic -> 10C3 = 10*9*8/3*2*1
long long solution1(int n, int r)
{
	long long res = 1;
	for(int i=0; i<r; i++)
	{
		res = res * (n-i);
		res = res / (i+1);
	}
	return res;
}

// 2. Print th row with given N
// One approach can be just traverse from 1 to N and use above function inside to compute the entire row
// Optimal Solution for this :
// For 6th Row : 1    5       10        10            5           1
//				     5/1  5/1*4/2  5/1*4/2*3/3  5/1*4/2*3/3*2/4
void solution2(int n)
{
	long long val = 1;
	cout<<val<<" ";
	for(int i=1; i<n; i++)
	{
		val = val * (n-i);
		val = val / (i);
	}
}

// 3. Print all rows from 1 to N
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    vector<int> temp = {1};
    ans.push_back(temp);
    for(int i=1; i<numRows; i++)
    {
        temp.resize(i+1);
        temp[0] = 1;
        temp[i] = 1;
        for(int j=1; j<i; j++)
            temp[j] = ans[i-1][j-1] + ans[i-1][j];
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
	
	return 0;
}