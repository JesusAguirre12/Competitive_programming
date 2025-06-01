//100
//gracias bianca!!
#include <bits/stdc++.h>
#define ll long long 
#define f first
#define s second
using namespace std;

struct point{
    ll x, y, d; 
};

int n;
vector<point>tree;
vector<pair<int,int>> vet;

point combine(point &a, point &b){
    ll dx, dy;
    if(a.d==0){
        dx=b.x;
        dy=b.y;
    }else if(a.d==1){
        dx=-b.y;
        dy=b.x;
    }else if(a.d==2){
        dx=-b.x;
        dy=-b.y;
    }else{
        dx=b.y;
        dy=-b.x;
    }
    return {a.x+dx, a.y+dy, (a.d + b.d)%4};
}

void build(){
    tree.resize(2*n);
    for(int i = 0; i < n; i++){
        if(vet[i].f==1){
            tree[n+i]={vet[i].s, 0, 0};
        }else{
            tree[n+i]={0, 0, vet[i].s%4};
        }
    }
    for(int i = n-1; i > 0; i--){
        tree[i]=combine(tree[i<<1], tree[i<<1|1]);
    }
}

void update(int idx, int t, int val){
    int p = n+idx;
    if(t==1){
        tree[p]={val,0,0};
    }else{
        tree[p]={0,0,val%4};
    }
    for(p>>=1;p>0;p>>=1){
        tree[p]=combine(tree[p<<1], tree[p<<1|1]);
    }
}

point query(int l, int r){
    point L = {0,0,0};
    point R = {0,0,0};
    l+=n;
    r+=n;
    while(l<=r){
        if(l&1){
            L=combine(L,tree[l++]);
        }
        if(!(r&1)){
            R=combine(tree[r--],R);
        }
        l>>=1;
        r>>=1;
    }
    return combine(L,R);
}

int main(){
    cin>>n;
    vet.resize(n);
    for(int i = 0; i < n; i++){
        cin >> vet[i].f >> vet[i].s;
    }
    build();
    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int l, r;
            cin >> l >> r;
            point res = query(l, r);
            cout << res.x << ' ' << res.y << ' ' << res.d << '\n';
        }else{
            int idx, t, val;
            cin >> idx >> t >> val;
            update(idx, t, val);
        }
    }
    return 0;
}
