#include<bits/stdc++.h>
using namespace std;
int chk[101010];
int main() {
	int n, k; scanf("%d %d", &n, &k);
	deque<int> q;

	memset(chk, -1, sizeof(chk));
	chk[n] = 0;
	q.push_back(n);
	while (q.size()) {
		int cur = q.front(); q.pop_front();
		int nx[] = { 2 * cur, cur - 1, cur + 1 };
		int nd[] = { 0, 1, 1 };
		if (cur == k) {
			printf("%d", chk[cur]);
			return 0;
		}
		for (int i = 0; i < 3; ++i) {
			if (0 <= nx[i] && nx[i] < 101010 && chk[nx[i]] == -1) {
				chk[nx[i]] = chk[cur] + nd[i];
				if (i == 0)
					q.push_front(nx[i]);
				else
					q.push_back(nx[i]);
			}
		}
	}
}
