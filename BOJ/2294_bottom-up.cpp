#include<bits/stdc++.h>
using namespace std;

int d[10010];
int n, k, tmp;

int main() {
	scanf("%d %d", &n, &k);

	vector<int> price(n);
	memset(d, 0x3f, sizeof(d));

	for (int i = 0; i < n; ++i) {
		scanf("%d", &price[i]);
		if (price[i] <= 10000)
			d[price[i]] = 1;
	}
	sort(price.begin(), price.end());
	for (int i = 1; i <= k; ++i)
		for (int j = 0; j < n && price[j] <= i; ++j)
			d[i] = min(d[i], d[i - price[j]] + 1);

	printf("%d", d[k] > 100000 ? -1 : d[k]);
}
