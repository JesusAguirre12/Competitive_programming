#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> visited;
int sz=0;
int dfs(int node){
    visited[node]=1;
    sz++;
    for(int nod : g[node]){
        if(!visited[nod]){
            dfs(nod);
        }
    }
    return sz;
}
int main(){
    int n,k;
    cin>> n >> k;
    g.resize(n+1);
    visited.resize(n+1);
    for(int i = 0; i < k; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            int ans=dfs(i);
            sz=0;
            v.push_back(ans);
        }
    }
    bitset<100001> dp;
    dp[0]=1;
    for(int i = 0; i < v.size(); i++){
        dp |= (dp << v[i]);
    }
    for(int i = 1; i <= n; i++){
        cout << dp[i];
    }
}