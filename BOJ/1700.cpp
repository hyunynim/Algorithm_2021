#include<bits/stdc++.h>
using namespace std;
vector<priority_queue<int>> q;
vector<int> plug;
int chk[111], ans;
int getMax(){
  int m = 0, mi = 0;
  for(int i = 0; i<plug.size(); ++i){
    if(q[plug[i]].empty()) return i;
    else if(-q[plug[i]].top() > m){
      m = -q[plug[i]].top();
      mi = i;
    }
  }
  return mi;
}
int main(){
  int n, k; scanf("%d %d", &n, &k);
  vector<int> seq(k);
  q.resize(k + 1);
  int cur = 0;
  for(int i = 0; i<k; ++i){
    scanf("%d", &seq[i]);
    q[seq[i]].push(-i);
    if(plug.size() < n && chk[seq[i]] == 0){
      plug.push_back(seq[i]);
      q[seq[i]].pop();
      chk[seq[i]] = 1;
      cur = i;
    }
    else if(plug.size() < n && chk[seq[i]])
      q[seq[i]].pop();
  }
  for(int i = cur + 1; i < k; ++i){
    if(chk[seq[i]] == 0){
      int nx = getMax();
      chk[plug[nx]] = 0;
      plug[nx] = seq[i];
      chk[seq[i]] = 1;
      ++ans;
    }
    q[seq[i]].pop();
  }

  printf("%d", ans);
}
