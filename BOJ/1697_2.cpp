#include<bits/stdc++.h>
using namespace std;
int chk[202020];
int main() {
	int n, k; scanf("%d %d", &n, &k);
	if (n >= k) {
		printf("%d", n - k);
		return 0;
	}
	queue<int> q;
	q.push(n);
	chk[n] = 1;
	while (q.size()) {
		auto cur = q.front(); q.pop();
		int nx[] = { cur - 1, cur + 1, cur * 2 };
		if (cur == k) {
			printf("%d", chk[cur] - 1);
			return 0;
		}
		for (int i = 0; i < 3; ++i) {
			if (0 <= nx[i] && nx[i] < 202020 && chk[nx[i]] == 0) {
				q.push(nx[i]);
				chk[nx[i]] = chk[cur] + 1;
			}
		}
	}
}
