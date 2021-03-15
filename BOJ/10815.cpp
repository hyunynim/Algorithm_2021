#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());

	int m; scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int num; scanf("%d", &num);
		printf("%d ", binary_search(seq.begin(), seq.end(), num));
	}
}
