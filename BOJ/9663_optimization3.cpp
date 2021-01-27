#include<bits/stdc++.h>
using namespace std;

int board[20];
int n, ans;

bool LocationCheck(int s, int x) {
    for (int i = s - 1; i >= 0; --i) 
        if (board[i] == x - i - 1 || board[i] == x + i + 1 || board[i] == x) return 0;
    return 1;
}
void go(int s) {
    if (s >= n) {
        ++ans;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (LocationCheck(s, i)) {
            if(!LocationCheck(s, i)) continue;
            board[s] = i;
            go(s + 1);
            board[s] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    go(0);
    printf("%d", ans);
}
