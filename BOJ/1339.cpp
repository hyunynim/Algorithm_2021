#include<bits/stdc++.h>
using namespace std;
int c2i[255];
int S2I(string& str) {
	int res = 0;
	for (auto i : str) {
		res = res * 10 + c2i[i];
	}
	return res;
}
int main() {
	int n; scanf("%d", &n);
	char msg[22];
	vector<string> seq;
	vector<char> alpha;
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		seq.push_back(msg);
		for (int j = 0; msg[j]; ++j) 
			alpha.push_back(msg[j]);
	}
	
	sort(alpha.begin(), alpha.end());
	alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());
	
	vector<int> p;
	for (int i = 0; i < alpha.size(); ++i)
		p.push_back(9 - i);
	int ans = 0;
	do {
		for (int i = 0; i < p.size(); ++i) 
			c2i[alpha[i]] = p[i];
		int sum = 0;
		for (auto i : seq) 
			sum += S2I(i);
		ans = max(ans, sum);
	} while (prev_permutation(p.begin(), p.end()));
	printf("%d", ans);
}
