#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	int ans = 0;
	for (int i = (1 << n) - 1; i > 0; --i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j))
				sum += seq[j];
		}
		if (sum == m)
			++ans;
	}
	printf("%d", ans);
}