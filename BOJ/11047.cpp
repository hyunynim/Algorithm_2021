#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	reverse(seq.begin(), seq.end());
	int ans = 0, i = 0;
	while (i < n && k) {
		ans += k / seq[i];
		k %= seq[i];
		++i;
	}
	printf("%d", ans);
}
