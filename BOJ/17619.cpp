#include<bits/stdc++.h>
using namespace std;
struct LINE {
	int s, e, i;
};
bool operator < (LINE l1, LINE l2) {
	return l1.s == l2.s ? l1.e < l2.e : l1.s < l2.s;
}
int idx[101010];
int main() {
	int n, q; scanf("%d %d", &n, &q);
	vector<LINE> seq(n);
	for (int i = 0; i < n; ++i) {
		int tmp; scanf("%d %d %d", &seq[i].s, &seq[i].e, &tmp);
		seq[i].i = i + 1;
	}
	sort(seq.begin(), seq.end());

	vector<LINE> comp;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (comp.empty() || !(comp.back().s <= seq[i].s && seq[i].s <= comp.back().e)) {
			idx[seq[i].i] = ++cur;
			comp.push_back(seq[i]);
		}
		else {
			comp.back().e = max(comp.back().e, seq[i].e);
			idx[seq[i].i] = cur;
		}
	}
	for (int i = 0; i < q; ++i) {
		int from, to; scanf("%d %d", &from, &to);
		if (idx[from] == idx[to])
			puts("1");
		else
			puts("0");
	}
}
