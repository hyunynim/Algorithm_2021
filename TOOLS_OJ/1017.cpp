#include<bits/stdc++.h>
using namespace std;
int d[2020][2020];
string seq;
bool isPal(int s, int e) {
	if (s == e) return 1;
	else if (e - s == 1)
		return seq[s] == seq[e];
	int& res = d[s][e];
	if (~res) return res;
	res = 0;
	if (seq[s] == seq[e])
		return res = isPal(s + 1, e - 1);
	return res;
}
int main() {
	memset(d, -1, sizeof(d));
	int n; cin >> n;
	char msg[2020]; cin >> msg;
	seq = msg;
	int m; scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int s, e; scanf("%d %d", &s, &e);
		printf("%d\n", isPal(s, e));
	}
}
