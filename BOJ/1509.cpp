#include<bits/stdc++.h>
using namespace std;
int chk[2525][2525];
vector<int> adj[2525];
char msg[2525];
int d[2525];
int c = 0;
bool pal(int l, int r) {
	if (l >= r) return 1;
	int& res = chk[l][r];
	if (~res) return res;
	res = 0;
	res = pal(l + 1, r - 1) && msg[l] == msg[r];
	if (res)
		adj[l].push_back(r + 1);

	pal(l + 1, r);
	pal(l, r - 1);
	return res;
}
int main() {
	memset(chk, -1, sizeof(chk));
	scanf("%s", msg);
	int sz = 0;
	for (; msg[sz]; ++sz) {
		chk[sz][sz] = 1;
		adj[sz].push_back(sz + 1);
	}
	pal(0, sz - 1);
	queue<int> q;
	q.push(0);
	d[0] = 1;
	while (q.size()) {
		int cur = q.front(); q.pop();
		if (cur == sz) {
			printf("%d", d[cur] - 1);
			return 0;
		}
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nx = adj[cur][i];
			if (d[nx] == 0) {
				d[nx] = d[cur] + 1;
				q.push(nx);
			}
		}
	}
}
