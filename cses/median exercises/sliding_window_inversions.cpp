#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> tree;
void build(const vector<int>& data){
    n = data.size();
    tree.clear();
    tree.resize(2*n);
    for(int i = 0; i < n; i++){
        tree[i+n] = {data[i]};
    }
    for(int i = n - 1; i > 0; i--){
        const auto& L = tree[i<<1];
        const auto& R = tree[i<<1|1];
        tree[i].resize(L.size()+R.size());
        merge(L.begin(), L.end(), R.begin(), R.end(), tree[i].begin());
    }
}
int queryLess(int l, int r, int x){
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1){
            res+=lower_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin();
            ++l;
        }
        if(r & 1){
            --r;
            res+=lower_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin();
        }
    }
    return res;
}
int queryGreat(int l, int r, int x){
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1){
            res+=tree[l].end() - upper_bound(tree[l].begin(), tree[l].end(), x);
            ++l;
        }
        if(r & 1){
            --r;
            res+=tree[r].end() - upper_bound(tree[r].begin(), tree[r].end(), x);
        }
    }
    return res;
}
 
int main(){
    int k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    build(v);
    long long tot = 0;
    for(int i = 0; i < k; i++){
        tot += queryLess(i,k,v[i]);
    }
    cout << tot << '\n';
    for(int i = k; i < n; i++){
        int out=v[i-k];
        int put=v[i];
        tot-=queryLess(i-k+1,i,out);
        tot+=queryGreat(i-k+1,i,put);
        cout << tot << '\n';
    }
}