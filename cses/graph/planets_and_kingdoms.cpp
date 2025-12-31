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
    reverse(topo.begin(),topo.end());
    for(auto node : topo){
        if(col[node]==-1){
            dfs2(node);
            t++;
        }
    }
    cout << t << '\n';
    for(int i = 0; i < n; i++){
        cout << col[i+1]+1 << ' ';
    }
}