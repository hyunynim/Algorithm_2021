#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> seq(9);
	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		scanf("%d", &seq[i]);
		sum += seq[i];
	}
	sort(seq.begin(), seq.end());
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - seq[i] - seq[j] == 100) {
				for (int k = 0; k < 9; ++k)
					if (k != i && k != j)
						printf("%d\n", seq[k]);
				return 0;
			} 
		}
	}
}
