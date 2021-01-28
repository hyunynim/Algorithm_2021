#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> seq(9), p;
	for (int i = 0; i < 9; ++i) {
		scanf("%d", &seq[i]);
		if (i < 2) p.push_back(0);
		else p.push_back(1);
	}
	sort(seq.begin(), seq.end());
	do {
		int sum = 0;
		for (int i = 0; i < 9; ++i)
			if (p[i]) sum += seq[i];
		if (sum == 100) {
			for (int i = 0; i < 9; ++i)
				if (p[i]) printf("%d\n", seq[i]);
			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));
}
