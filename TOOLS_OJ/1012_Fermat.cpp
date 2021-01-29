#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return res;
}
ll fact(ll n) {
	ll res = 1;
	for (ll i = 1; i <= n; ++i)
		res = (res * i) % mod;
	return res;
}
int main() {
	int n, r; scanf("%d %d", &n, &r);
	ll a = fact(n);
	ll b = pow(fact(r), mod - 2);
	ll c = pow(fact(n - r), mod - 2);

	printf("%lld", (((a * b) % mod) * c) % mod);
}
