#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n;
vector<int> lazy;
vector<bool> vis;
vector<int> sets;
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

void apply1(int node, int l, int r, int val){
    tree[node]+=val*(r-l+1);
    if(vis[node]){
        sets[node]+=val;
    }else{
        lazy[node]+=val;
    } 
    
}

void apply2(int node, int l, int r, int val){
    tree[node]=val*(r-l+1);
    lazy[node]=0;
    sets[node]=val;
    vis[node]=1;
}

void push(int node, int l, int r){
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    if(lazy[node]!=0){
        apply1(node<<1,l,mid,lazy[node]);
        apply1(node<<1|1,mid+1,r,lazy[node]);
        lazy[node]=0;
    }
    if(vis[node]){
        apply2(node<<1,l,mid,sets[node]);
        apply2(node<<1|1,mid+1,r,sets[node]);
        vis[node]=0;
    }
}

void update1(int node, int l, int r, int ql, int qr, int val){
    if(qr<l || r<ql){
        return;
    }
    if(ql<=l&&qr>=r){
        apply1(node,l,r,val);
        return;
    }
    int mid=(l+r)>>1;
    push(node,l,r);
    update1(node<<1,l,mid,ql,qr,val);
    update1(node<<1|1,mid+1,r,ql,qr,val);
    tree[node]=tree[node<<1]+tree[node<<1|1];
}


void update2(int node, int l, int r, int ql, int qr, int val){
    if(qr<l || r<ql){
        return;
    }
    if(ql<=l&&qr>=r){
        apply2(node,l,r,val);
        return;
    }
    int mid=(l+r)>>1;
    push(node,l,r);
    update2(node<<1,l,mid,ql,qr,val);
    update2(node<<1|1,mid+1,r,ql,qr,val);
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
    vis.assign(4*n+4,0);
    sets.resize(4*n+4);
    tree.resize(4*n+4);
    for(int i = 1; i <= n; i++){
        cin >> vet[i];
    }
    build(1,1,n);
    while(q--){
        int t,l,r;
        cin>>t >> l >> r;
        if(t==1){
            int v;
            cin >> v;
            update1(1,1,n,l,r,v);
        }else if(t==2){
            int v;
            cin >> v;
            update2(1,1,n,l,r,v);
        }else{
            cout << query(1,1,n,l,r) << '\n';
        }
    }
}