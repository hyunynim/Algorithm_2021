#include<bits/stdc++.h>
using namespace std;
struct EDGE {
	int to, w;
};
vector<EDGE> adj[101010];
bool operator < (EDGE e1, EDGE e2) {
	return e1.w > e2.w;
}
vector<int> Dijkstra(int st, int v) {
	vector<int> ans(v + 1);
	vector<int> chk(v + 1);
	fill(ans.begin(), ans.end(), 1e9);
	priority_queue<EDGE> q;
	q.push({ st, 0 });
	ans[st] = 0;
	while (q.size()) {
		auto cur = q.top(); q.pop();
		int x = cur.to, w = cur.w;
		if (chk[x]) continue;
		chk[x] = 1;
		for (auto nx : adj[x]) {
			if (ans[nx.to] > w + nx.w) {
				ans[nx.to] = w + nx.w;
				q.push({ nx.to, w + nx.w });
			}
		}
	}
	return ans;
}
