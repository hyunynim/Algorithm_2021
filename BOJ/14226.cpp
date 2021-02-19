#include<bits/stdc++.h>
using namespace std;
int chk[2020][2020];
struct EMO {
	int x, c;
};
int main() {
	int s; scanf("%d", &s);
	chk[1][0] = 1;
	queue<EMO> q;
	q.push({ 1, 0 });
	while (q.size()) {
		auto cur = q.front(); q.pop();
		int x = cur.x, c = cur.c;
		if (x == s) {
			printf("%d", chk[x][c] - 1);
			return 0;
		}
		int nx[] = { x, x + c, x - 1 };
		int nc[] = { x, c, x };
		for (int i = 0; i < 3; ++i) {
			if (0 <= nx[i] && nx[i] < 2020 && 0 <= nc[i] && nc[i] < 2020 && chk[nx[i]][nc[i]] == 0) {
				chk[nx[i]][nc[i]] = chk[x][c] + 1;
				q.push({ nx[i], nc[i] });
			}
		}
	}
}
