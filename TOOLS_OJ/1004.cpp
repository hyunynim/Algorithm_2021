#include<bits/stdc++.h>
using namespace std;
int cnt[10101];
int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        int num; scanf("%d", &num);
        ++cnt[num];
    }
    for(int i = 0; i<10101; ++i)
        if(cnt[i])
            printf("%d %d\n", i, cnt[i]);
}
