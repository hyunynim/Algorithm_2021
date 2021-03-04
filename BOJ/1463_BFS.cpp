#include<bits/stdc++.h>
using namespace std;
int chk[1010101];
int main(){
    int n; scanf("%d", &n);
    queue<int> q;
    q.push(n);
    chk[n] = 1;
    while(q.size()){
        int cur = q.front(); q.pop();
        if(cur == 1){
            printf("%d", chk[cur] - 1);
            return 0;
        }
        
        vector<int> next;
        if(cur % 3 == 0)
            next.push_back(cur / 3);
        if(cur % 2 == 0)
            next.push_back(cur / 2);
        next.push_back(cur - 1);
        for(auto nx : next){
            if(chk[nx] == 0){
                chk[nx] = chk[cur] + 1;
                q.push(nx);
            }
        }
    }
}
