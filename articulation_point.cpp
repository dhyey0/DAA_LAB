
#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int> adj[], int V, vector<int>& vis,
		int i, int curr)
{
	vis[curr] = 1;
	for (auto x : adj[curr]) {
		if (x != i) {
			if (!vis[x]) {
				dfs(adj, V, vis, i, x);
			}
		}
	}
}

void AP(vector<int> adj[], int V)
{
	for (int i = 1; i <= V; i++) {


		int components = 0;

		
		vector<int> vis(V + 1, 0);

		
		for (int j = 1; j <= V; j++) {
			if (j != i) {

				
				if (!vis[j]) {

					
					components++;

					dfs(adj, V, vis, i, j);
				}
			}
		}
		
		if (components > 1) {
			cout << i << "\n";
		}
	}
}
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	cout << "Articulation points in the graph \n";
	int V = 5;
	vector<int> adj1[V + 1];
	addEdge(adj1, 1, 2);
	addEdge(adj1, 2, 3);
	addEdge(adj1, 1, 3);
	addEdge(adj1, 3, 4);
	addEdge(adj1, 4, 5);
	AP(adj1, V);

	return 0;
}
