#include<bits/stdc++.h>
using namespace std;

int chk[20202];
vector<int> adj[20202];
struct NODE {
	int x, c;
};
bool BFS(int s) {
	chk[s] = 0;
	queue<NODE> q;
	q.push({ s, 0 });
	while (q.size()) {
		auto cur = q.front(); q.pop();
		int x = cur.x, c = cur.c;
		for (auto nx : adj[x]) {
			if (chk[nx] == -1) {
				chk[nx] = (c ^ 1);
				q.push({ nx, c ^ 1 });
			}
			else if (chk[nx] == c)
				return 0;
		}
	}
	return 1;
}

int main() {
	int k; scanf("%d", &k);
	while (k--) {
		memset(chk, -1, sizeof(chk));
		int v, e; scanf("%d %d", &v, &e);
		
		for (int i = 0; i < 20202; ++i)
			adj[i].clear();

		for (int i = 0; i < e; ++i) {
			int from, to; scanf("%d %d", &from, &to);
			adj[from].push_back(to);
			adj[to].push_back(from);
		}
		bool ans = 1;
		for (int i = 1; i <= v; ++i) {
			if (~chk[i]) continue;
			if (!BFS(i)) {
				ans = 0; break;
			}
		}
		if (ans)
			puts("YES");
		else
			puts("NO");
	}
}
