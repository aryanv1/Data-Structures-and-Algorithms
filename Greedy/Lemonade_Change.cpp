#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool lemonadeChange(vector<int>& bills) 
{
	int five = 0, ten = 0;
	for (int i : bills) {
		if (i == 5) five++;
		else if (i == 10) five--, ten++;
		else if (ten > 0) ten--, five--; // if five is not >=1 then it will become less than 0 and loop will break
		else five -= 3;
		if (five < 0) return false;
	}
	return true;
}

int main()
{
	
	return 0;
}