#include<bits/stdc++.h>
using namespace std;
const int VMAX = 101010;
const int inf = 1e8;
struct EDGE {
	int to, w;
};
vector<EDGE> adj[VMAX];
bool operator < (EDGE e1, EDGE e2) {
	return e1.w > e2.w;
}
vector<int> dijkstra(int s) {
	vector<int> ans(VMAX);
	fill(ans.begin(), ans.end(), inf);
	priority_queue<EDGE> q;
	q.push({ s, 0 });
	ans[s] = 0;
	while (q.size()) {
		int cur = q.top().to, d = q.top().w;
		q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nextV = adj[cur][i].to, nextD = adj[cur][i].w + d;
			if (ans[nextV] > nextD) {
				ans[nextV] = nextD;
				q.push({ nextV, nextD });
			}
		}
	}
	return ans;
}

int main() {
	int v, e, t1, t2;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; ++i) {
		int from, to, w;
		scanf("%d %d %d", &from, &to, &w);
		adj[from].push_back({ to, w });
		adj[to].push_back({ from, w });
	}
	scanf("%d %d", &t1, &t2);
	vector<int> ans = dijkstra(1);
	int res[2] = { 0 };
	res[0] = ans[t1];
	res[1] = ans[t2];
	ans = dijkstra(t1);
	res[0] += ans[t2];
	res[1] += ans[v];
	ans = dijkstra(t2);
	res[0] += ans[v];
	res[1] += ans[t1];
	res[0] = min(res[0], res[1]);
	printf("%d", res[0] < inf ? res[0] : -1);
}
