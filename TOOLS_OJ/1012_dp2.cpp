#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll d[2020][2020];
ll comb(int n, int r) {
	if (n - r == 1 || r == 1)
		return n;
	if (n == r || r == 0)
		return 1;

	ll& res = d[n][r];
	if (~res) return res;
	return res = (comb(n - 1, r - 1) % mod + comb(n - 1, r) % mod) % mod;
}
int main() {
	memset(d, -1, sizeof(d));
	int n, r; scanf("%d %d", &n, &r);
	printf("%lld", comb(n, r));
}
