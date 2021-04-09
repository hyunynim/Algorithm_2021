#include<bits/stdc++.h>
using namespace std;
struct EDGE {
	int to, w;
};
vector<EDGE> adj[10101];
int dis[10101];
bool chk[10101];
void go(int s, int w) {
	if (chk[s]) return;
	chk[s] = 1;
	dis[s] = w;
	for (int i = 0; i < adj[s].size(); ++i)
		go(adj[s][i].to, w + adj[s][i].w);
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	go(1, 0);
	int ans = 0, ansI = 0;
	for (int i = 1; i <= n; ++i)
		if (dis[i] > ans)
			ans = dis[i], ansI = i;
	memset(dis, 0, sizeof(dis));
	memset(chk, 0, sizeof(chk));
	go(ansI, 0);
	ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dis[i]);
	printf("%d", ans);
}
