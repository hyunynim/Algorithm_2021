#include<bits/stdc++.h>
using namespace std;
int board[22][22];
int tmp[22][22];
vector<int> pick;
int n, ans;
void move() {
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };
    int sx[] = { 0, 0, n, 0 };
    int ex[] = { n, n, 0, n };
    int sy[] = { n, 0, 0, 0 };
    int ey[] = { 0, n, n, n };
    int dxi[] = { 1, 1, -1, 1 };
    int dyi[] = { -1, 1, 1, 1 };
    for (auto d : pick) {
         for (int k = 0; k < n; ++k) {
            for (int i = sx[d]; i * dxi[d] <= ex[d] * dxi[d]; i += dxi[d]) {
                for (int j = sy[d]; j * dyi[d] <= ey[d] * dyi[d]; j += dyi[d]) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (0 <= nx && nx < n && 0 <= ny && ny < n
                        && 0 <= i && i < n && 0 <= j && j < n) {
                        if (tmp[i][j] == 0) {
                            tmp[i][j] = tmp[nx][ny];
                            tmp[nx][ny] = 0;
                        }
                    }
                }
            }
        }

        for (int i = sx[d]; i * dxi[d] <= ex[d] * dxi[d]; i += dxi[d]) {
            for (int j = sy[d]; j * dyi[d] <= ey[d] * dyi[d]; j += dyi[d]) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (0 <= nx && nx < n && 0 <= ny && ny < n
                    && 0 <= i && i < n && 0 <= j && j < n) {
                    if (tmp[i][j] == tmp[nx][ny]) {
                        tmp[i][j] *= 2;
                        tmp[nx][ny] = 0;
                    }
                }
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = sx[d]; i * dxi[d] <= ex[d] * dxi[d]; i += dxi[d]) {
                for (int j = sy[d]; j * dyi[d] <= ey[d] * dyi[d]; j += dyi[d]) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (0 <= nx && nx < n && 0 <= ny && ny < n
                        && 0 <= i && i < n && 0 <= j && j < n) {
                        if (tmp[i][j] == 0) {
                            tmp[i][j] = tmp[nx][ny];
                            tmp[nx][ny] = 0;
                        }
                    }
                }
            }
        }
    }


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans = max(ans, tmp[i][j]);
}
void go(int toPick) {
    if (toPick == 0) {
        memcpy(tmp, board, sizeof(board));
        move();
        return;
    }
    for (int i = 0; i < 4; ++i) {
        pick.push_back(i);
        go(toPick - 1);
        pick.pop_back();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &board[i][j]);

    go(5);
    printf("%d", ans);
}
