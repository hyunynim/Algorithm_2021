#include<bits/stdc++.h>
using namespace std;
struct EDGE {
	int to, w;
};
vector<EDGE> adj[101010];
vector<int> Dijkstra(int st, int v) {
	vector<int> ans(v + 1);
	vector<int> chk(v + 1);
	fill(ans.begin(), ans.end(), 1e9);
	ans[st] = 0;
	int cur, m;
	while (1) {
		cur = -1, m = 1e9;
		for (int i = 1; i <= v; ++i) {
			if (chk[i] == 0 && ans[i] < m) {
				m = ans[i];
				cur = i;
			}
		}
		if (cur == -1) break;
		for (auto nx : adj[cur]) {
			ans[nx.to] = min(ans[nx.to], ans[cur] + nx.w);
		}
	}
	return ans;
}
