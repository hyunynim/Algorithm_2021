#include<bits/stdc++.h>
using namespace std;

#define VMAX 432
#define INF 1e9
int n, m, a, b, w;

int graph[VMAX][VMAX];

void floyd() {
	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			graph[i][j] = INF;
			if (i == j)
				graph[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a; --b;
		graph[a][b] = min(graph[a][b], 1);
	}
	floyd();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] >= INF)
				graph[i][j] = 0;
		}
	}
	int s;
	scanf("%d", &s);
	for (int i = 0; i < s; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a; --b;
		if (graph[a][b] == graph[b][a] && graph[a][b] == 0)
			printf("0\n");
		else if (graph[a][b])
			printf("-1\n");
		else
			printf("1\n");
	}
}
