#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());
	for (int i = 0; i < n; ++i) {
		int l = i + 1, r = n - 1;
		while (l < r) {
			int sum = seq[i] + seq[l] + seq[r];
			if (sum == 0) {
				printf("%d %d %d", seq[r], seq[i], seq[l]);
				return 0;
			}
			if (sum > 0)
				--r;
			else
				++l;
		}
	}
	printf("-1");
}
