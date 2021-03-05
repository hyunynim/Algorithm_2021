#include<bits/stdc++.h>
using namespace std;

int d[10101];
int n, k;
vector<int> seq;

int go(int s, int cur) {
	if (s == n) {
		if (cur == 0)
			return 0;
		else
			return 100000;
	}
	int& res = d[cur];
	if (res != -1 && res < 1000000)
		return res;
	res = 123456789;
	for (int i = 0; seq[s] * i <= cur; ++i)
		res = min(res, go(s + 1, cur - i * seq[s]) + i);
	return res;
}

int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &k);
	seq.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());
	int ans = go(0, k);
	printf("%d", ans > 50000 ? -1 : ans);
}
