#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n, s; scanf("%d %d", &n, &s);
	vector<int> seq[2];
	for (int i = 0; i < n; ++i) {
		int num; scanf("%d", &num);
		seq[i % 2].push_back(num);
	}
	vector<int> sum[2];
	for (int k = 0; k < 2; ++k) {
		for (int i = (1 << seq[k].size()) - 1; i >= 0; --i) {
			int cur = 0;
			for (int j = 0; j < seq[k].size(); ++j) {
				if (i & (1 << j))
					cur += seq[k][j];
			}
			sum[k].push_back(cur);
		}
		sort(sum[k].begin(), sum[k].end());
	}
	vector<pair<int, ll>> comp[2];
	for (int k = 0; k < 2; ++k) {
		for (auto i : sum[k]) {
			if (comp[k].empty() || comp[k].back().first != i)
				comp[k].push_back({ i, 1 });
			else
				++comp[k].back().second;
		}
	}
	int l = 0, r = comp[1].size() - 1;
	ll ans = 0;
	while (l < comp[0].size() && 0 <= r) {
		auto cur1 = comp[0][l];
		auto cur2 = comp[1][r];
		auto cur = cur1.first + cur2.first;
		if (cur == s) {
			ans += cur1.second * cur2.second;
			++l; --r;
		}
		else if (cur > s)
			--r;
		else
			++l;
	}
	if (s == 0) --ans;
	printf("%lld", ans);
}
