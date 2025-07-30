#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isBipartite(int V,vector<int> adj[]) 
{
	vector<int> col(V, -1);  
  // queue for BFS storing {vertex , colour}
	queue<pair<int, int> > q; 
	for (int i = 0; i < V; i++) 
	{
    //if not coloured
		if (col[i] == -1) 
		{    
			q.push({i,0});
			col[i] = 0;   
			while (!q.empty())
			{
				pair<int, int> p = q.front();
				q.pop();
				//current vertex
				int v = p.first;
				//colour of current vertex
				int c = p.second;   
				//traversing vertexes connected to current vertex
				for (int j : adj[v]) 
				{    
					//if already coloured with parent vertex color
					//then bipartite graph is not possible
					if (col[j] == c)
						return 0;        
					//if uncoloured
					if (col[j] == -1) 
					{
					//colouring with opposite color to that of parent
						col[j] = !c;
						q.push({j, col[j]});
					}
				}
			}
		}
	}
	return 1;
}

int main()
{
	int V, E;
	V = 4 , E = 8;
      //adjacency list for storing graph
	vector<int> adj[V];
	adj[0] = {1,3};
	adj[1] = {0,2};
	adj[2] = {1,3};
	adj[3] = {0,2};


	bool ans = isBipartite(V, adj);
    //returns 1 if bipartite graph is possible
	if (ans)
		cout << "Yes\n";
    //returns 0 if bipartite graph is not possible
	else
		cout << "No\n";

	return 0;
}
// Time Complexity - O(V+E)
//Space Complexity - O(V)