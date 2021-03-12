#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		priority_queue<ll> q;
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			ll num; scanf("%lld", &num);
			q.push(-num);
		}
		ll ans = 0;
		while (q.size() > 1) {
			ll num1 = q.top(); q.pop();
			ll num2 = q.top(); q.pop();
			q.push(num1 + num2);
			ans -= (num1 + num2);
		}
		printf("%lld\n", ans);
	}
}
