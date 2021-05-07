#include<bits/stdc++.h>
using namespace std;
int cost[11][11];
int chk[1 << 11][11];
struct CUR {
	int x, s, c;
};
bool operator < (CUR c1, CUR c2) {
	return c1.c > c2.c;
}
int main() {
	memset(chk, 0x3f, sizeof(chk));
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &cost[i][j]);
	priority_queue<CUR> q;
	q.push({ k, 1 << k, 0 });
	while (q.size()) {
		int x = q.top().x, s = q.top().s, c = q.top().c; q.pop();
		if (s == (1 << n) - 1) {
			printf("%d", c); return 0;
		}
		for (int i = 0; i < n; ++i) {
			if (i == x) continue;
			if (c + cost[x][i] < chk[s][i]) {
				chk[s][i] = c + cost[x][i];
				q.push({ i, s | (1 << i), c + cost[x][i] });
			}
		}
	}
}
