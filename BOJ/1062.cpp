#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k; scanf("%d %d", &n, &k);
	if (k < 5) {
		printf("0");
		return 0;
	}
	char msg[22];
	string tmp = "";
	vector<int> seq;

	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		int s = 0;
		for (int j = 0; msg[j]; ++j) 
			s |= (1 << (msg[j] - 'a'));
		seq.push_back(s);
		tmp += msg;
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	
	string str = "acint", word = "";
	for (int i = 0; i < tmp.size(); ++i) {
		bool chk = 1;
		for (int j = 0; j < str.size(); ++j) {
			if (tmp[i] == str[j]) {
				chk = 0; break;
			}
		}
		if (chk)
			word.push_back(tmp[i]);
	}
	k -= 5;
	vector<int> p;
	for (int i = 0; i < word.size(); ++i) {
		if (i < k)
			p.push_back(1);
		else
			p.push_back(0);
	}
	int ans = 0;
	do {
		int s = 0;
		for (int i = 0; i < str.size(); ++i)
			s |= (1 << (str[i] - 'a'));
		for (int i = 0; i < p.size(); ++i)
			s |= (p[i] << (word[i] - 'a'));

		int cnt = 0;
		for (int i = 0; i < seq.size(); ++i) 
			if ((s & seq[i]) == seq[i]) ++cnt;
		ans = max(ans, cnt);
	} while (prev_permutation(p.begin(), p.end()));
	printf("%d", ans);
}
