#include<bits/stdc++.h>
using namespace std;
int adj[505][505];
int path[505][505];
const int inf = 1e9;
void PrintPath(int u, int v) {
	if (path[u][v] == u)
		printf("%d ", u);
	else 
		PrintPath(u, path[u][v]);
	printf("%d ", v);
}
void FloydWarshall(int v) {
	for (int k = 1; k <= v; ++k) {
		for (int i = 1; i <= v; ++i) {
			for (int j = 1; j <= v; ++j) {
				int next = adj[i][k] + adj[k][j];
				if (adj[i][j] > next) {
					adj[i][j] = next;
					path[i][j] = k;
				}
			}
		}
	}
}
void InputAdjList() {
	memset(adj, 0x3f, sizeof(adj));
	int v, e; scanf("%d %d", &v, &e);
	for (int i = 0; i < e; ++i) {
		int from, to, w; scanf("%d %d %d", &from, &to, &w);
		adj[from][to] = min(adj[from][to], w);
		path[from][to] = from;
	}
}
void InputAdjMatrix() {
	int v; scanf("%d", &v);
	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j) {
			scanf("%d", &adj[i][j]);
			if (adj[i][j] == 0 && (i != j))
				adj[i][j] = inf;
			else
				path[i][j] = i;
		}
	}
}
