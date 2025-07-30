#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int wordLadderLength(string beginword, string endword, vector<string>& wordlist) 
{
    queue<pair<string,int>> q;
    unordered_set<string> s(wordlist.begin(),wordlist.end());
    q.push({beginword,1});
    s.erase(beginword);
    while(!q.empty())
    {
        string word = q.front().first;
        int count = q.front().second;
        q.pop();
        if(word == endword) return count;
        for(int i=0; i<word.size(); i++)
        {
            char original = word[i];
            for(char c='a'; c<='z'; c++)
            {
                word[i] = c;
                //If updated word is present in the wordlist or not
                if(s.find(word) != s.end())
                {
                    q.push({word,count+1});
                    s.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main()
{
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	vector<string> s;
	for(int i=0; i<n; i++)
	{
		string k;
		cin>>k;
		s.push_back(k);
	}
	int m = wordLadderLength(s1,s2,s);
	cout<<m<<endl;
	return 0;
}
/*Input
5
der
dfs
des der dfr dgt dfs

Time Complexity - O(n*wordlength*26)
Space Complexity - O(n*complexity of set)
*/