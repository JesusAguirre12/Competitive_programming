#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll bellmanFord(int n, vector<vector<int>>& edges){
    vector<ll> dist(n+1,-1e18);
    dist[1]=0; 
    vector<int> sus;
    for(int i = 1; i <= n; i++){
        bool ok=0;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            ll val = edge[2];
            if(dist[u] != -1e18 && dist[u]+val > dist[v]){
                if(i==n){
                    sus.push_back(v);
                }
                dist[v]=dist[u]+val;
                ok=1;
            }
        }
        if(!ok){
            break;
        }
    }
    vector<vector<int>> g(n+1);
    for(auto &nod : edges){
        g[nod[0]].push_back(nod[1]);
    }
    vector<bool> visited(n+1,0);
    queue<int> q;
    for(auto nod : sus){
        q.push(nod);
        visited[nod]=1;
    }
    while(!q.empty()){
        int nod = q.front(); q.pop();
        if(nod == n){
            return -1;
        }
        for(int v : g[nod]){
            if(!visited[v]){
                visited[v]=1;
                q.push(v);
            }
        }
    }
    return dist[n];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }
    cout << bellmanFord(n,edges);
}