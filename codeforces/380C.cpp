#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n;
struct node{
    int open;
    int closed;
    int ans;
};
vector<node> tree;
node merge(node a, node b){
    int totadd=min(a.open,b.closed);
    return {a.open+b.open-totadd, b.closed+a.closed-totadd, a.ans+b.ans+totadd};
}
void build(string vet){
    n=vet.length();
    tree.assign(2*n, {0,0,0});
    for(int i = 0; i < n; i++){
        if(vet[i]=='('){
            tree[n+i]={1,0,0};
        }else{
            tree[n+i]={0,1,0};
        }
    }
    for(int i = n-1; i > 0; i--){
        tree[i]=merge(tree[i<<1],tree[i<<1|1]);
    }
}
node query(int l, int r){
    l+=n;
    r+=n;
    node left={0,0,0};
    node right={0,0,0};
    while(l<r){
        if(l&1){
            left=merge(left,tree[l++]);
        }
        if(r&1){
            right=merge(tree[--r],right);
        }
        l>>=1;
        r>>=1;
    }
    return merge(left,right);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string vet;
    cin>> vet;
    int q; 
    cin >> q;
    build(vet);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        cout << (query(l,r).ans<<1) << '\n';
    }
}