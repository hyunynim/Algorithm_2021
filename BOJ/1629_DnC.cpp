#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a, ll n, ll m) {
	if (n <= 0) return 1 % m;
	if (n == 1) return a % m;
	if (n % 2)
		return ((a % m) * (pow(a, n - 1, m) % m)) % m;
	else {
		ll res = pow(a, n / 2, m) % m;
		return (res * res) % m;
	}
}
int main() {
	ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", pow(a, b, c));
}
