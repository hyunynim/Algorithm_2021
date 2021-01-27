#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; string str; cin >> n >> str;
    for(int i = 0; i<=n-i-1; ++i){
        if(str[i] != str[n - i - 1]){
            printf("0");
            return 0;
        }
    }
    printf("1");
}
