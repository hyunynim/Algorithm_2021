#include<bits/stdc++.h>
using namespace std;
int chk[101010];
int main() {
	int n, k; scanf("%d %d", &n, &k);
	queue<int> q1, q2;

	memset(chk, -1, sizeof(chk));

	q2.push(n);
	chk[n] = 0;
	while (q1.size() || q2.size()) {
		int cur;
		if (q1.size()) {
			cur = q1.front(); q1.pop();
		}
		else{
			cur = q2.front(); q2.pop();
		}
		if (cur == k) {
			printf("%d", chk[cur]);
			return 0;
		}
		int nx[] = { 2 * cur, cur - 1, cur + 1};
		int nd[] = { 0, 1, 1 };
		for (int i = 0; i < 3; ++i) {
			if (0 <= nx[i] && nx[i] < 101010 && chk[nx[i]] == -1) {
				chk[nx[i]] = chk[cur] + nd[i];
				if (i == 0)
					q1.push(nx[i]);
				else
					q2.push(nx[i]);
			}
		}
	}
}
