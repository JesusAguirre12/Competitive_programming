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
 
void dfs2(int node){
    col[node]=t;
    for(auto nod : g2[node]){
        if(col[nod]==-1)dfs2(nod);
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n  >> m;
    vector<int> co(n+1);
    for(int i = 1; i <= n; i++){
        cin>> co[i];
    }
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
    reverse(topo.begin(),topo.end());
    vector<int> comp;
    for(auto node : topo){
        if(col[node]==-1){
            dfs2(node);
            comp.push_back(t);
            t++;
        }
    }
    vector<int> dp(t+1,0LL), cant(t+1,0LL);
    vector<vector<int>> con(t+1);
    for(int i = 1; i <= n; i++){
        dp[col[i]]+=co[i];
        cant[col[i]]+=co[i];
        for(auto node : g[i]){
            if(col[i]!=col[node]){
                con[col[i]].push_back(col[node]);
            }
        }
    }
    for(auto node : comp){
        for(auto nod : con[node]){
            dp[nod]=max(dp[nod],dp[node]+cant[nod]);
        }
    }
    int ans=0LL;
    for(int i = 0; i < t; i++){
        ans=max(ans,dp[i]);
    }
    cout << ans;
}