#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{int s,e;};
const int maxn = 2e5+2;
int vet[maxn], tree[4*maxn];
void build(int node, int tl, int tr){
    if (tl == tr) {
        tree[node] = vet[tl];
        return;
    }
    int m = (tl + tr) >> 1;
    build(2*node + 1, tl, m);
    build(2*node + 2, m + 1, tr);
    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}
 
void update(int node, int tl, int tr, int p, int v){
    if (tl == tr) {
        tree[node] = v;
        return;
    }
    int m = (tl + tr) >> 1;
    if (p <= m) update(2*node + 1, tl, m, p, v);
    else        update(2*node + 2, m + 1, tr, p, v);
    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}
 
int findk(int node, int tl, int tr, int k){
    if (tl == tr) return tl;
    int m = (tl + tr) >> 1;
    if (tree[2*node + 1] >= k)
        return findk(2*node + 1, tl, m, k);
    else
        return findk(2*node + 2, m + 1, tr, k - tree[2*node + 1]);
}
int32_t main(){
    unordered_map<int,int>mp;
    fill_n(vet,maxn,1);
    build(0,0,maxn-1);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto&i:v){cin>>i;}
    for(int i = 0; i < k; i++){
        if(v[i]<=2e5){update(0,0,maxn-1,v[i],0);}
        mp[v[i]]++;
    }
    cout << findk(0,0,maxn-1,1) << '\n';
    for(int i = k; i < n; i++){
        if(v[i-k]<=2e5){mp[v[i-k]]--;if(mp[v[i-k]]==0){update(0,0,maxn-1,v[i-k],1);}}
        if(v[i]<=2e5){update(0,0,maxn-1,v[i],0);mp[v[i]]++;};
        cout << findk(0,0,maxn-1,1) << '\n';
    }
}