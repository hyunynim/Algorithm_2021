#include<bits/stdc++.h>
using namespace std;
struct BOX {
	int to, w;
};
vector<BOX> adj[2020];
int to[2020];
int main() {
	int n, c, m; scanf("%d %d %d", &n, &c, &m);
	for (int i = 0; i < m; ++i) {
		int from, to, w; scanf("%d %d %d", &from, &to, &w);
		adj[from].push_back({ to, w });
	}
	int ans = 0;
	int r = 1;
	for (int i = 1; i <= n; ++i) {
		ans += to[i];
		to[i] = 0;
		for (auto cur : adj[i]) 
			to[cur.to] += cur.w;
		
		int w = c;
		bool flag = 0;
		for (int j = i + 1; w && j <= n; ++j) {
			if (!flag) {
				if (to[j] < w)
					w -= to[j];
				else {
					to[j] = w;
					flag = 1;
				}
			}
			else
				to[j] = 0;
		}
	}
	printf("%d", ans);
}
