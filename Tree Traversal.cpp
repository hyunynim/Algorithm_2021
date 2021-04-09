#include<bits/stdc++.h>
using namespace std;
vector<int> adj[101010];
void PreOrder(int s) {
	printf("%d ", s);
	PreOrder(adj[s][0]);
	PreOrder(adj[s][1]);
}
void InOrder(int s) {
	InOrder(adj[s][0]);
	printf("%d ", s);
	InOrder(adj[s][1]);
}
void PostOrder(int s) {
	PostOrder(adj[s][0]);
	PostOrder(adj[s][1]);
	printf("%d ", s);
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	PreOrder(1);
	InOrder(1);
	PostOrder(1);
}
