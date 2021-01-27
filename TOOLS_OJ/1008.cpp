#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d", &n);
    int num;
    map<int, int> chk;
    for(int i = 0; i<n; ++i){
        scanf("%d", &num);
        if(chk[-num]){
            printf("%d %d", num, -num);
            return 0;
        }
        ++chk[num];
    }
    printf("-1");
}
