#include<bits/stdc++.h>
using namespace std;
vector<int> adj[33];
void pre(int s) {
	if (s == -1) return;
	printf("%c", s + 'A');
	pre(adj[s][0]);
	pre(adj[s][1]);
}
void in(int s) {
	if (s == -1) return;
	in(adj[s][0]);
	printf("%c", s + 'A');
	in(adj[s][1]);
}
void post(int s) {
	if (s == -1) return;
	post(adj[s][0]);
	post(adj[s][1]);
	printf("%c", s + 'A');
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[3][10];
		for (int j = 0; j < 3; ++j)
			scanf("%s", msg[j]);
		int p = msg[0][0] - 'A', l = -1, r = -1;
		if (msg[1][0] != '.')
			l = msg[1][0] - 'A';
		if (msg[2][0] != '.')
			r = msg[2][0] - 'A';
		adj[p].push_back(l);
		adj[p].push_back(r);
	}
	pre(0);	puts("");
	in(0); 	puts("");
	post(0);
}
