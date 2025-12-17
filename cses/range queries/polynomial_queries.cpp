#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n;
vector<int> lazy;
vector<int> diff;
vector<int> tree;
 
vector<int> vet;
void build(int node, int l, int r){
    if(l==r){
        tree[node]=vet[r];
        return;
    }
    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    tree[node]=tree[node<<1]+tree[node<<1|1];
}
 
void apply(int node, int l, int r, int v, int diff1){
    int cant=(r-l+1);
    tree[node]+=diff1*((cant*(cant-1))/2)+v*(cant);
    lazy[node]+=v;
    diff[node]+=diff1;
}
 
void push(int node, int l, int r){
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    apply(node<<1,l,mid,lazy[node],diff[node]);
    apply(node<<1|1,mid+1,r,lazy[node]+diff[node]*(mid-l+1),diff[node]);
    lazy[node]=0;
    diff[node]=0;
}
 
void update(int node, int l, int r, int ql, int qr){
    if(qr<l || r<ql){
        return;
    }
    if(ql<=l&&qr>=r){
        apply(node,l,r,-ql+l+1,1);
        return;
    }
    int mid=(l+r)>>1;
    push(node,l,r);
    update(node<<1,l,mid,ql,qr);
    update(node<<1|1,mid+1,r,ql,qr);
    tree[node]=tree[node<<1]+tree[node<<1|1];
}
 
 
int query(int node, int l, int r, int ql, int qr){
    if(qr<l || r<ql){
        return 0;
    }
    if(ql<=l&&qr>=r){
        return tree[node];
    }
    int mid=(l+r)>>1;
    push(node,l,r);
    return query(node<<1,l,mid,ql,qr)+query(node<<1|1,mid+1,r,ql,qr);
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    vet.resize(n+1);
    lazy.assign(4*n+4,0);
    diff.resize(4*n+4,0);
    tree.resize(4*n+4);
    for(int i = 1; i <= n; i++){
        cin >> vet[i];
    }
    build(1,1,n);
    while(q--){
        int t,l,r;
        cin>>t >> l >> r;
        if(t==1){
            update(1,1,n,l,r);
        }else{
            cout << query(1,1,n,l,r) << '\n';
        }
    }
}
