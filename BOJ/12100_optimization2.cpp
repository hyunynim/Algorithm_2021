#include<bits/stdc++.h>
using namespace std;
int board[22][22];
int tmp[22][22];
vector<int> pick;
int n, ans;
void Rotate(int t) {
    int rot[22][22];
    for (int k = 0; k < t; ++k) {
        memcpy(rot, tmp, sizeof(tmp));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                tmp[i][j] = rot[j][n - i - 1];
    }
}
void Move() {
    for (auto r : pick) {
        Rotate(r);
        for (int i = 0; i < n; ++i) {
            int l = 0, r = 1;
            while (l < n && r < n) {
                if (l >= r) {
                    ++r; continue;
                }
                if (tmp[i][l] == 0 && tmp[i][r]) {
                    tmp[i][l] = tmp[i][r];
                    tmp[i][r] = 0;
                    ++r;
                }
                else if (tmp[i][r] == 0) {
                    ++r;
                }
                else {
                    if (tmp[i][l] == tmp[i][r]) {
                        tmp[i][l] *= 2;
                        tmp[i][r] = 0;
                        ++l; ++r;
                    }
                    else {
                        ++l;
                    }
                }
            }
        }
    }
}
void go(int toPick) {
    if (toPick == 0) {
        memcpy(tmp, board, sizeof(board));
        Move();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans = max(ans, tmp[i][j]);
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
