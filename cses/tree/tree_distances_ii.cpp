#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
vector<vector<int>> g(2e5+5);
vector<int> sz(2e5+5);
vector<ll> ans(2e5+5);
void calc(int node, int pa){
    sz[node]=1;
    ans[node]=0;
    for(auto nod : g[node]){
        if(nod==pa){
            continue;
        }
        calc(nod,node);
        sz[node]+=sz[nod];
        ans[node]+=ans[nod]+sz[nod];
    }
}
void solve(int node, int pa){
    if(pa!=-1){
        ans[node]=ans[pa]-sz[node]+n-sz[node];
    }
    for(auto nod : g[node]){
        if(nod!=pa){
            solve(nod,node);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    calc(1,-1);
    solve(1,-1);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << '\n';
    }
}