#include<bits/stdc++.h>
using namespace std;
vector<int> adj[2][505];
int chk[2][505];
void go(int s, int c) {
	if (chk[c][s]) return;
	chk[c][s] = 1;
	for (auto nx : adj[c][s]) 
		go(nx, c);
}
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		adj[0][a].push_back(b);
		adj[1][b].push_back(a);
	}

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		memset(chk, 0, sizeof(chk));
		go(i, 0);
		go(i, 1);
		int cnt = 0;
		for (int j = 1; j <= n; ++j)
			if (chk[0][j] || chk[1][j]) ++cnt;
		if (cnt == n) ++ans;
	}
	printf("%d", ans);
}
