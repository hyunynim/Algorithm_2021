#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
void merge(vector<int> &seq, int l, int r) {
	vector<int> tmp;
	int mid = (l + r) / 2;
	int f = l, s = mid + 1;
	while (f <= mid && s <= r) {
		if (seq[f] <= seq[s]) 
			tmp.push_back(seq[f++]);
		else {
			tmp.push_back(seq[s++]);
			ans += mid - f + 1;
		}
	}
	for (; f <= mid; ++f)
		tmp.push_back(seq[f]);
	for (; s <= r; ++s)
		tmp.push_back(seq[s]);
	for (int i = l; i <= r; ++i)
		seq[i] = tmp[i - l];
}

void merge_sort(vector<int> & seq, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		merge_sort(seq, l, mid);
		merge_sort(seq, mid + 1, r);
		merge(seq, l, r);
	}
}
int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	merge_sort(seq, 0, n - 1);
	printf("%lld", ans);
}
