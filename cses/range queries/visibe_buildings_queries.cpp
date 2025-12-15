#include <bits/stdc++.h>
#define int long long 
using namespace std;
vector<int> tree;
int n;
struct qquery{
    int l,r,idx;
};
void build(vector<int>&vet){
    for(int i = 0; i < n; i++){
        tree[n+i]=vet[i];
    }
    for(int i = n-1; i > 0; i--){
        tree[i]=tree[i<<1]+tree[i<<1|1];
    }
}
void update(int pos, int val){
    pos+=n;
    tree[pos]=val;
    for(pos>>=1; pos>0; pos>>=1){
        tree[pos]=tree[pos<<1]+tree[pos<<1|1];  
    }
}
int query(int l, int r){
    l+=n;
    r+=n;
    int ans=0;
    while(l<r){
        if(l&1) ans+=tree[l++];
        if(r&1) ans+=tree[--r];
        l>>=1;
        r>>=1;
    }
    return ans;
}
int32_t main(){
    int qu;
    cin >> n >> qu;
    vector<int>vet(n);
    tree.assign(2*n+1,0);
    for(int i = 0; i < n; i++){
        cin>> vet[i];
    }
    build(vet);
    vector<qquery> q(qu);
    for(int i = 0; i <qu; i++){
        int a,b;
        cin >> a >> b;
        q[i]={a,b,i};
    }
    sort(q.begin(), q.end(), [&](qquery a, qquery b){
        return a.l > b.l;
    });
    int curr=n;
    stack<int> pi;
    vector<int> ans(qu);
    for(auto nod:q){
        while(curr>(nod.l-1)){
            curr--;
            while(!pi.empty() && vet[pi.top()] <= vet[curr]){
                update(pi.top(),0);
                pi.pop();
            }
            pi.push(curr);
            update(curr,1);
        }
        ans[nod.idx]=query(nod.l-1,nod.r);
    }
    for(auto i : ans){
        cout << i << '\n';
    }
    
}