#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
const ll inf = (ll)1e16;
#define V_MAX 4040
vector<P> adj[V_MAX];
int v, e, st = 1;

vector<ll> dijkstra(int st) {
	bool chk[V_MAX] = { 0 };
	priority_queue<P, vector<P>, greater<P>> q;
	vector<ll> ans;
	ans.resize(V_MAX + 1);

	q.push({ 0, st });
	fill(ans.begin(), ans.end(), inf);
	int sz = 1;
	ans[st] = 0;
	while (q.size()) {
		ll x = q.top().second;
		ll d = q.top().first;
		q.pop();
		if (chk[x])
			continue;
		chk[x] = 1;
		++sz;
		for (auto p : adj[x]) {
			if (p.second + d < ans[p.first]) {
				ans[p.first] = p.second + d;
				q.push({ p.second + d , p.first });
			}
		}
	}
	return ans;
}

vector<ll> dijkstra2(int st) {
	bool chk[V_MAX][2] = { 0 };
	priority_queue<T, vector<T>, greater<T>> q;
	vector<ll> ans;
	ans.resize(V_MAX + 1);

	q.push({ 0, 0, st });
	fill(ans.begin(), ans.end(), inf);
	int sz = 1;
	ans[st] = 0;
	while (q.size()) {
		ll x, d, cnt;
		tie(d, cnt, x) = q.top();
		q.pop();
		if (chk[x][cnt%2])
			continue;
		chk[x][cnt%2] = 1;
		++sz;
		for (auto p : adj[x]) {
			int nd;
			if (cnt % 2)
				nd = p.second * 2;
			else
				nd = p.second / 2;
			if (nd + d < ans[p.first]) {
				ans[p.first] = nd + d;
			}
			q.push({ nd + d , cnt + 1, p.first });
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &v, &e);
	ll a, b, w;
	for (int i = 0; i < e; ++i) {
		scanf("%lld %lld %lld", &a, &b, &w);
		w *= 10;
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	int ans = 0;
	vector<ll> fox = dijkstra(st);
	vector<ll> wo = dijkstra2(st);
	for (int i = 1; i <= v; ++i) {
		if (fox[i] < wo[i])
			++ans;
	}
	printf("%d", ans);
	return 0;
}
