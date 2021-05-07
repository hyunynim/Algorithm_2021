#include<bits/stdc++.h>
using namespace std;
#define MAX_V 1010
#define INF (int)1e9

int v, e;
vector<pair<int, int> > edge[2][MAX_V];

void dijkstra(int start, vector<int> & ans, bool isGo) {
	ans.resize(v);
	fill(ans.begin(), ans.end(), INF);
	ans[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));

	while (pq.size()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (ans[cur] < cost) continue;

		for (int i = 0; i < edge[isGo][cur].size(); ++i) {
			int toGo = edge[isGo][cur][i].first;
			int nextDist = cost + edge[isGo][cur][i].second;

			if (ans[toGo] > nextDist) {
				ans[toGo] = nextDist;
				pq.push(make_pair(-nextDist, toGo));
			}
		}
	}
}
int main() {
	int x;
	scanf("%d %d %d", &v, &e, &x);
	--x;
	for (int i = 0; i < e; ++i) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		--a; --b;
		edge[0][a].push_back({ b, w });
		edge[1][b].push_back({ a, w });
	}
	vector<int> tmp[2];
	vector<pair<int, int>> ans;
	dijkstra(x, tmp[0], 0);
	dijkstra(x, tmp[1], 1);
	int maxDis = 0;
	for (int i = 0; i < tmp[0].size(); ++i) {
		if (i == x)
			continue;
		maxDis = max(maxDis, tmp[0][i] + tmp[1][i]);
	}
	printf("%d", maxDis);
}
