#include<bits/stdc++.h>
using namespace std;

int n, ans;

void go(int s, int left, int right, int chk) {
    if (s >= n) {
        ++ans;
        return;
    }
    for (int i = 0; i < n; ++i){
        if ((left & (1 << i)) || (right & (1 << i)) || (chk & (1 << i))) continue;
        go(s + 1, (left | (1 << i)) << 1, (right | (1 << i)) >> 1, chk | (1 << i));
    }
}

int main() {
    scanf("%d", &n);
    go(0, 0, 0, 0);
    printf("%d", ans);
}
