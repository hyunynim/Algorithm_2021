#include<bits/stdc++.h>
using namespace std;

bool board[20][20];
bool prevBoard[20][20][20];
int n, ans;

void SaveBoard(int s) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            prevBoard[s][i][j] = board[i][j];
}

void RestoreBoard(int s) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            board[i][j] = prevBoard[s][i][j];
}

void LocationCheck(int x, int y) {
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    for (int i = 0; i < 8; ++i) {
        int nx = x, ny = y;
        while (0 <= nx && nx < n && 0 <= ny && ny < n) {
            board[nx][ny] = 1;
            nx += dx[i];
            ny += dy[i];
        }
    }
}
void go(int s) {
    if (s >= n) {
        ++ans;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!board[s][i]) {
            SaveBoard(s);
            LocationCheck(s, i);
            go(s + 1);
            RestoreBoard(s);
        }
    }
}
       
int main() {
    scanf("%d", &n);
    go(0);
    printf("%d", ans);
}
