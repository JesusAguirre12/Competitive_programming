#include <bits/stdc++.h>
#define int long long
#define ll long long 
using namespace std;
int n,q;
struct node{
    ll ans;
    int le,ri;
};
vector<int> raices;
vector<node> tree;
int add(node nodo){
    tree.push_back(nodo);
    return tree.size()-1;
}
int build(int l, int r, vector<int>&vet){
    if(l==r){
        node nodo={vet[l],-1,-1};
        return add(nodo);
    }
    int mid = (l+r)>>1;
    int lo=build(l,mid,vet);
    int hi=build(mid+1,r,vet);
    node nodo={tree[hi].ans+tree[lo].ans,lo,hi};
    return add(nodo);
}
int update(int nod, int l, int r, int pos, int val){
    if(l==r){
        node nodo={val,-1,-1};
        return add(nodo);
    }
    int mid = (l+r)>>1;
    int lo=tree[nod].le;
    int hi=tree[nod].ri;
    if(pos <= mid){
        lo=update(lo,l,mid,pos,val);
    }else{
        hi=update(hi,mid+1,r,pos,val);
    }
    node nodo={tree[hi].ans+tree[lo].ans,lo,hi};
    return add(nodo);
}
ll query(int nod, int l, int r, int ql, int qr){
    if(l>qr||r<ql){
        return 0;
    }
    if(l>=ql&&qr>=r){
        return tree[nod].ans;
    }
    int mid=(l+r)>>1;
    return query(tree[nod].le,l,mid,ql,qr)+query(tree[nod].ri,mid+1,r,ql,qr);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    vector<int> vet(n+1);
    for(int i = 1; i <= n; i++){
        cin >> vet[i];
    }
    raices.push_back(build(1,n,vet));
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int k,pos,val;
            cin>>k>>pos>>val;
            k--; 
            int ra=update(raices[k],1,n,pos,val);
            raices[k]=ra;
        }else if(t==2){
            int k,l,r;
            cin >> k >> l >> r;
            k--;
            cout << query(raices[k],1,n,l,r) << '\n';
        }else{
            int k;
            cin >> k;
            k--;
            raices.push_back(raices[k]);
        }
    }
}
