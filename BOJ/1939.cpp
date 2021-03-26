#include<bits/stdc++.h>
using namespace std;
int s, t, n, m;
struct EDGE {
	int to, w;
};
vector<EDGE> adj[10101];
bool chk(int mid) {
	bool chk[10101] = { 0 };
	queue<EDGE> q;
	chk[s] = 1;
	q.push({ s, (int)1e9 });
	while (q.size()) {
		int cur = q.front().to, w = q.front().w;
		q.pop();
		if (cur == t && w >= mid)
			return 1;
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nx = adj[cur][i].to, nw = adj[cur][i].w;
			if (!chk[nx] && nw >= mid) {
				chk[nx] = 1;
				q.push({ nx, nw });
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &n, &m);
	int l = 1e9, r = 0, ans = 0;
	for (int i = 0; i < m; ++i) {
		int from, to, w;
		scanf("%d %d %d", &from, &to, &w);
		adj[from].push_back({ to, w });
		adj[to].push_back({ from, w });
        l = min(l, w);
        r = max(r, w);
	}
	scanf("%d %d", &s, &t);
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (chk(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	printf("%d", ans);
}
