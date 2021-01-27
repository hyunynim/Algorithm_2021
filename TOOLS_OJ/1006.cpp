#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    int num;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        ++cnt[num];
    }
    for (auto i : cnt) {
        printf("%d %d\n", i, i.second);
    }

}
