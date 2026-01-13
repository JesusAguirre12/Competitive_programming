#include <bits/stdc++.h>
#define int long long 
using namespace std;
vector<vector<int>> g(1e5+5), g2(1e5+5);
vector<bool> visited(1e5+5,0);
vector<int> topo, col(1e5+5,-1);
int t=0;
 
void dfs1(int node){
    visited[node]=1;
    for(auto nod : g[node]){
        if(!visited[nod])
            dfs1(nod);
    }
    topo.push_back(node);
}
 
int32_t main(){
    int n,m;
    cin >> n  >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g2[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    vector<bitset<50000>> dp(n+1);
    for(auto node : topo){
        dp[node][node]=1;
        for(auto nod : g[node]){
            dp[node]|=dp[nod];
        }
    }
    for(int i = 1; i <= n; i++){
        cout << dp[i].count() << ' ';
    }
}