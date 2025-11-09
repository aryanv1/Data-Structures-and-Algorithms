#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

// Finding the index at which given n will come in Gray Code sequence
int grayCode(int n)
{
    int res = 0;
    while (n)
    {
        res ^= n;
        n >>= 1;
    }
    return res;
}

int main()
{

    return 0;
}