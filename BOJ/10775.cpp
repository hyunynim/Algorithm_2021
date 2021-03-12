#include<bits/stdc++.h>
using namespace std;
int main(){
  int g, p; scanf("%d %d", &g, &p);
  set<int> s;
  for(int i = 0; i<g; ++i)
    s.insert(i + 1);
  int ans = 0;

  for(int i = 0; i<p; ++i){
    if(s.empty()) break;
    int num; scanf("%d", &num);
    auto it = s.lower_bound(num);
    if(it == s.end()) --it;
    if(it != s.end() && *it > num){
      if(it == s.begin()) break;
      --it;
    }
    s.erase(it);
    ++ans;
  }
  printf("%d\n", ans);
}
