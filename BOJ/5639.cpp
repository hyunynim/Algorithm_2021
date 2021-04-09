#include<bits/stdc++.h>
using namespace std;
vector<int> seq;
vector<int> adj[10101];
void go(int l, int r) {
	if (l >= r) return;
	int idx = l + 1;
	for (; idx <= r; ++idx)
		if (seq[idx] > seq[l]) break;
	if (idx != l + 1) {
		adj[l].push_back(l + 1);
		go(l + 1, idx - 1);
	}
	if (idx <= r) {
		adj[l].push_back(idx);
		go(idx, r);
	}
}
void post(int s) {
	if(adj[s].size())
		post(adj[s][0]);
	if(adj[s].size() > 1)
		post(adj[s][1]);
	printf("%d\n", seq[s]);
}
int main() {
	int num;
	while (~scanf("%d", &num)) seq.push_back(num);
	go(0, seq.size() - 1);
	post(0);
}
