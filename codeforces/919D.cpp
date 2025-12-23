#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> g(3e5+5);
vector<int> visited(3e5+5,0); 
vector<int> topo;
bool ci=0;
void dfs(int node){
    visited[node]=1; 
    for(int nod : g[node]){
        if(visited[nod]==0){
            dfs(nod);
            if(ci){
                return;
            }
        }
        else if(visited[nod]==1){
            ci=1;
            return;
        }
    }
    visited[node]=2;
    topo.push_back(node);
}
int32_t main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            dfs(i);
            if(ci){
                cout << -1;
                return 0;
            }
        }
    }
    reverse(topo.begin(), topo.end());
    vector<vector<int>> dp(n+1, vector<int>(26,0));
    int ans=0;
    for(int node : topo){
        dp[node][s[node-1]-'a']++;
        for(int nod : g[node]){
            for(int i = 0; i < 26; i++){
                dp[nod][i]=max(dp[nod][i],dp[node][i]);
            }
        }
        for(int i = 0; i < 26; i++)
            ans=max(ans,dp[node][i]);
    }
    cout << ans;
}
