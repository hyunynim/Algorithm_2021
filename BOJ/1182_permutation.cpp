#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, s; scanf("%d %d", &n, &s);
    vector<int> seq(n);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &seq[i]);
        for (int j = 0; j < n; ++j) {
            if (j < n - i - 1) p[i].push_back(0);
            else p[i].push_back(1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        do {
            int sum = 0;
            for (int j = 0; j < n; ++j)
                if (p[i][j] == 1)
                    sum += seq[j];
            if (sum == s) ++ans;
        } while (next_permutation(p[i].begin(), p[i].end()));
    }
    printf("%d", ans);
}
