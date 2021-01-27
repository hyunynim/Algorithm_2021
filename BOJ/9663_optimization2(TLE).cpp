#include<bits/stdc++.h>
using namespace std;

bool board[20][20];
int n, ans;

bool LocationCheck(int x, int y) {
    int dx[] = { -1, -1, -1 };
    int dy[] = { -1, 0, 1 };
    for (int i = 0; i < 3; ++i) {
        int nx = x, ny = y;
        while (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (board[nx][ny]) return 0;
            nx += dx[i];
            ny += dy[i];
        }
    }
    return 1;
}
void go(int s) {
    if (s >= n) {
        ++ans;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!board[s][i]) {
            if(!LocationCheck(s, i)) continue;
            board[s][i] = 1;
            go(s + 1);
            board[s][i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    go(0);
    printf("%d", ans);
}
