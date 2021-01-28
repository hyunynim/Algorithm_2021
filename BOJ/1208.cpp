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

	auto l = sum[0].begin();
	auto r = lower_bound(sum[1].begin(), sum[1].end(), sum[1].back());
	ll ans = 0;
	while (l != sum[0].end()) {
		ll cur = *l + *r;
		auto next1 = upper_bound(sum[0].begin(), sum[0].end(), *l);
		auto next2 = upper_bound(sum[1].begin(), sum[1].end(), *r);

		if (cur == s) {
			ll cnt1 = next1 - l;
			ll cnt2 = next2 - r;
			ans += (cnt1 * cnt2);
			l = next1;
			if (r != sum[1].begin())
				r = lower_bound(sum[1].begin(), sum[1].end(), *(r - 1));
			else
				break;
		}
		else if (cur > s) {
			if (r != sum[1].begin())
				r = lower_bound(sum[1].begin(), sum[1].end(), *(r - 1));
			else
				break;
		}
		else 
			l = next1;
	}
	if (s == 0) --ans;
	printf("%lld", ans);
}
