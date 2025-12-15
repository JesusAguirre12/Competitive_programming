#include <bits/stdc++.h>
#define int long long 
using namespace std;
 
int n;
vector<int> vet;
 
struct node{
    int pref;
    int suf;
    int sum;
    int best;
};
 
vector<node> tree;
 
node merge(node l, node r){
    int pref=max(l.pref,l.sum+r.pref);
    int suf=max(r.suf,r.sum+l.suf);
    int sum=l.sum+r.sum;
    int best=max({l.best,r.best,l.suf+r.pref});
    return {pref,suf,sum,best};
}
 
void build(){
    for(int i = 0; i < n; i++){
        tree[n+i]={max(vet[i],0LL),max(vet[i],0LL),vet[i],max(vet[i],0LL)};
    }
    for(int i = n-1; i > 0; i--){
        tree[i]=merge(tree[i<<1],tree[i<<1|1]);
    }
}
 
void update(int pos, int val){
    pos+=n;
    tree[pos]={max(val,0LL),max(val,0LL),val,max(val,0LL)};
    for(pos >>= 1; pos > 0; pos >>=1){
        tree[pos]=merge(tree[pos<<1],tree[pos<<1|1]);
    }
}
 
int query(int l, int r){
    l+=n;
    r+=n;
    node left={0,0,0,0};
    node right={0,0,0,0};
    while(l<r){
        if(l&1){
            left=merge(left,tree[l]);
            l++;
        }
        if(r&1){
            r--;
            right=merge(tree[r],right);
        }
        l>>=1;
        r>>=1;
    }
    auto cosa=merge(left,right);
    return cosa.best;
}
 
int32_t main(){
    int q;
    cin >> n >> q; 
    vet.resize(n);
    tree.resize(2*n+1);
    for(int i = 0; i < n; i++){
        cin >> vet[i];
    }
    build();
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        cout << query(a,b) << '\n';
    }
}