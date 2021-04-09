#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10101];
vector<int> level[20];
int x;
void go(int s, int h) {
	if (s == -1) return;
	go(adj[s][0], h + 1);
	level[h].push_back(x++);
	go(adj[s][1], h + 1);
}
int main() {
	int n; scanf("%d", &n);
	int parent[10101] = { 0 };
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(b);
		adj[a].push_back(c);
		if (b != -1) parent[b] = a;
		if (c != -1) parent[c] = a;

	}
	int st = 0;
	for (int i = 1; i <= n; ++i) {
		if (parent[i] == 0) {
			st = i; break;
		}
	}
	go(st, 1);
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < 20; ++i) {
		if (level[i].size() > 1) {
			if (ans2 < level[i].back() - level[i][0] + 1) {
				ans2 = level[i].back() - level[i][0] + 1;
				ans1 = i;
			}
		}
		else if (level[i].size()) {
			if (ans2 < 1) {
				ans2 = 1;
				ans1 = i;
			}
		}
	}
	printf("%d %d", ans1, ans2);
}
