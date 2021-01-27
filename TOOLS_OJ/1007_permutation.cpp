#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d", &n);
    vector<int> seq(n), p(n - 2);  
    p.push_back(1);  p.push_back(1);
    for(int i = 0; i<n; ++i)
        scanf("%d", &seq[i]);
    do{
        int sum = 0;
        vector<int> ans;
        for(int i = 0; i<n; ++i){
            if(p[i] == 1){
                sum += seq[i];   
                ans.push_back(seq[i]);
            }
        }
        if(sum == 0){
            printf("%d %d", ans[0], ans[1]);
            return 0;
        }
    } while(next_permutation(p.begin(), p.end()));
    printf("-1");
}
