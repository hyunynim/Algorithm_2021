#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& seq, int l, int r) {
    vector<int> tmp;
    int mid = (l + r) / 2;
    int f = l, s = mid + 1;
    while (f <= mid && s <= r) {
        if (seq[f] <= seq[s])
            tmp.push_back(seq[f++]);
        else 
            tmp.push_back(seq[s++]);
    }
    for (; f <= mid; ++f)
        tmp.push_back(seq[f]);
    for (; s <= r; ++s)
        tmp.push_back(seq[s]);
    for (int i = l; i <= r; ++i)
        seq[i] = tmp[i - l];
}

void MergeSort(vector<int>& seq, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        MergeSort(seq, l, mid);
        MergeSort(seq, mid + 1, r);
        merge(seq, l, r);
    }
}
int main() {
    srand(time(0));
    int n; scanf("%d", &n);
    vector<int> seq(n);
    for (int i = 0; i < n; ++i)
        seq[i] = rand() % 100 + 1;
    MergeSort(seq, 0, n - 1);
    for (auto i : seq)
        printf("%d ", i);
}
