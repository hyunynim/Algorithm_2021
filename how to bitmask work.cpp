#include<bits/stdc++.h>
using namespace std;
void GetBitmask(int n, int num) {
	string res = "";
	while (num) {
		res.push_back((num % 2) + '0');
		num /= 2;
	}
	while (res.size() < n)
		res.push_back('0');
	printf("%s\n", res.c_str());
}
int main() {
	int n, s; scanf("%d %d", &n, &s);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	for (int i = (1 << n) - 1; i > 0; --i) {
		int num = i;
		puts("------------------------------------");
		printf("현재 인덱스: %d\n\n", i);
		int sum = 0;
		printf("%10s: ", "수열");
		for (int j = 0; j < n; ++j) {
			printf("%-4d", seq[j]);
			if (i & (1 << j))
				sum += seq[j];
		}
		puts("");
		printf("%10s: ", "비트마스크");
		for (int j = 0; j < n; ++j) {
			printf("%-4d", num % 2);
			num /= 2;
		}
		puts("\n");
		printf("선택한 수의 합: %d\n", sum);
		puts("------------------------------------\n\n");

	}
}
