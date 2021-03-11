#include<bits/stdc++.h>
using namespace std;
struct LINE {
	int s, e;
};
int main() {
	int n; scanf("%d", &n);
	vector<LINE> seq;
	for (int i = 0; i < n; ++i) {
		int s, e; scanf("%d %d", &s, &e);
		if (seq.empty())
			seq.push_back({ s, e });
		else {
			if (seq.back().s <= s && s <= seq.back().e)
				seq.back().e = max(seq.back().e, e);
			else
				seq.push_back({ s, e });
		}
	}
	int ans = 0;
	for (auto i : seq) 
		ans += i.e - i.s;
	printf("%d", ans);
}
