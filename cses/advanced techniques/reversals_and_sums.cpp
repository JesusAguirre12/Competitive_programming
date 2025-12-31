#include <bits/stdc++.h>
#define int long long 
using namespace std;
struct node{
    int val;
    int pr, sz;
    int l, r;
    bool rev;
    int sum=0;
};
vector<node> tr(4e5+5);
int nodes=0;
int root=0;
int new_node(int val){
    nodes++;
    tr[nodes].val = val;
    tr[nodes].pr = rand();
    tr[nodes].sz = 1;
    tr[nodes].l=tr[nodes].r=0;
    tr[nodes].rev=0;
    tr[nodes].sum=val;
    return nodes;
}
int sz(int t){
    return t ? tr[t].sz : 0;
}
void push(int t){
    if(!t || !tr[t].rev) return;
    swap(tr[t].l, tr[t].r);
    if(tr[t].l) tr[tr[t].l].rev ^= 1;
    if(tr[t].r) tr[tr[t].r].rev ^= 1;
    tr[t].rev = 0;
}
void upd(int t){
    if(t){
        int suml = tr[t].l ? tr[tr[t].l].sum : 0;
        int sumr = tr[t].r ? tr[tr[t].r].sum : 0;
        tr[t].sz =1+sz(tr[t].l)+sz(tr[t].r);
        tr[t].sum =tr[t].val+suml+sumr;
    }
}
void split(int t, int k, int &a, int &b){
    if(!t){
        a=b=0;
        return;
    }
    push(t);
    if(sz(tr[t].l) >= k){
        split(tr[t].l,k,a,tr[t].l);
        b=t;
        upd(b);
    }else{
        split(tr[t].r,k-sz(tr[t].l)-1,tr[t].r, b);
        a=t;
        upd(a);
    }
}
int merge(int a, int b){
    if(!a || !b) return a ? a : b;
    if(tr[a].pr > tr[b].pr){
        push(a);
        tr[a].r = merge(tr[a].r, b);
        upd(a);
        return a;
    }else{
        push(b);
        tr[b].l = merge(a, tr[b].l);
        upd(b);
        return b;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(712367);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = merge(root, new_node(x));
    }
    while(m--){
        int t;
        int a, b;
        cin >>t >> a >> b;
        int t1, t2, t3;
        split(root,b,t1,t3);
        split(t1,a-1,t1,t2);
        if(t==1){
            tr[t2].rev^=1;
        }else{
            cout << tr[t2].sum << '\n';
        }
        root=merge(t1,t2);         
        root=merge(root,t3);       
    }
}
