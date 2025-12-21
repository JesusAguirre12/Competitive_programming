#include <bits/stdc++.h>
#define ll long long 
#define int long long 
#define f first 
#define s second
using namespace std;
vector<vector<int>> g(2e5+5);
vector<bool> visited(2e5+5,0);
vector<int> topo;
void dfs(int node){
    visited[node]=1;
    for(auto nod : g[node]){
        if(!visited[nod]){
            dfs(nod);
        }
    }
    topo.push_back(node);
}
int32_t main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    vector<int> dp(2e5,0);
    
    dp[1]=1;
    for(auto node : topo){
        for(auto nod: g[node]){
            dp[nod]+=dp[node];
            dp[nod]%=(int)(1e9+7);
        }
    }
    cout << dp[n] << '\n';
}