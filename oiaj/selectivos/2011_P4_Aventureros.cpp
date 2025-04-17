//96 pts
#include <bits/stdc++.h>
using namespace std;
void open(string name = ""){
    cin.tie(0)->sync_with_stdio(0); 
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
struct F{
    int n;
    vector<int> t;
    F(int n): n(n), t(n+1,0){}
    int s(int i){
        int r=0;
        for(; i; i-= i & -i) r+= t[i];
        return r;
    }
    void u(int i, int d){
        for(; i<=n; i+= i & -i) t[i]+= d;
    }
    int f(int x){
        int r=0;
        for(int b=1<<(31-__builtin_clz(n)); b; b>>=1){
            int j=r+b;
            if(j<=n && t[j]<x){ x-= t[j]; r=j; }
        }
        return r+1;
    }
};
int main(){
    open("aventureros");
    int n; cin >> n;
    vector<long long> a(n-1);
    for(int i=0;i<n-1;i++) cin >> a[i];
    F P(n);
    for(int i=1;i<=n;i++) P.u(i,1);
    int l=n, c=1;
    vector<int> e;
    for(int i=0;i<n-1;i++){
        long long s=a[i]%l;
        int q=P.s(n)-P.s(c-1), k;
        if(q>s){ int y=P.s(c-1)+s+1; k=P.f(y); }
        else { s-=q; int y=s+1; k=P.f(y); }
        e.push_back(k);
        P.u(k,-1);
        l--;
        if(l){
            if(P.s(n)-P.s(k)) c=P.f(P.s(k)+1);
            else c=P.f(1);
        }
    }
    int o=P.f(1);
    for(int i=0;i<e.size();i++) cout << e[i] << (i+1<e.size()?" ":"\n");
    cout << o << "\n";
    return 0;
}