#include<bits/stdc++.h>
using namespace std;
vector<int> adj[55];
int del;
int go(int s) {
	if (s == del) return 0;
	if (adj[s].empty() || (adj[s].size() == 1 && adj[s][0] == del))
		return 1;
	int res = 0;
	for (int i = 0; i < adj[s].size(); ++i)
		res += go(adj[s][i]);
	return res;
}
int main() {
	int n, st; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int num; scanf("%d", &num);
		if (num == -1) st = i;
		else
			adj[num].push_back(i);
	}
	scanf("%d", &del);
	printf("%d", go(st));
}
