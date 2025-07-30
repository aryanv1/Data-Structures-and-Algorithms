#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <int> calculateSpan(int price[], int n)
{
	vector<int> ans;
	stack<pair<int,int>> st;
	for(int i=0; i<n; i++)
	{
		int span=1;
		while(!st.empty() && st.top().first <= price[i]){
			span+=st.top().second;
			st.pop();
		} 
		st.push({price[i],span});
		ans.push_back(span);
	}
	return ans;
}

int main()
{
	int price[] = {100, 80, 60, 70, 60, 75, 85};
	int n = 7;
	vector<int> ans = calculateSpan(price,n);
	for(int i=0; i<n; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}