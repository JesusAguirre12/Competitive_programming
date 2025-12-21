#include <bits/stdc++.h>
#define ll long long 
#define int long long 
#define f first 
#define s second
using namespace std;
vector<vector<int>> g(1e5+5);
vector<bool> visited(1e5+5,0);
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    vector<int> dp(1e5+5,-1), parent(1e5+5,-1);
    
    dp[1]=0;
    for(auto node : topo){
        if(dp[node]==-1) continue;
        for(auto nod: g[node]){
            if(dp[node]+1>dp[nod]){
                dp[nod]=dp[node]+1;
                parent[nod]=node;
            }
        }
    }
    int node=n;
    vector<int> ans;
    ans.push_back(n);
    while(parent[node]!=-1){
        node=parent[node];
        ans.push_back(node);
    }
    reverse(ans.begin(),ans.end());
    if(dp[n]==-1){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << ans.size() << '\n';
        for(auto i : ans){
            cout << i << ' ';
        }
    }
}