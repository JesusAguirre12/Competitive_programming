#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int n, m;
    cin >> n>> m;
    vector<vector<pair<int,int>>> g(n+1), g2(n+1);
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a>> b >> c;
        g[a].push_back({b,c});
        g2[b].push_back({a,c});
    }
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0LL,1});
    vector<ll> dist(n, 1e18);
    dist[0]=0;
    vector<bool> visited(n+1,0);
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(visited[node]){
            continue;
        }
        visited[node]=1;
        for(auto & [nod, val] : g[node]){
            if(dist[node-1]+val < dist[nod-1]){
                dist[nod-1]=dist[node-1]+val;
                pq.push({dist[nod-1],nod});
            }
        }
    }
    
    pq.push({0LL,n});
    vector<ll> dist2(n, 1e18);
    dist2[n-1]=0;
    vector<bool> visited2(n+1,0);
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(visited2[node]){
            continue;
        }
        visited2[node]=1;
        for(auto & [nod, val] : g2[node]){
            if(dist2[node-1]+val < dist2[nod-1]){
                dist2[nod-1]=dist2[node-1]+val;
                pq.push({dist2[nod-1],nod});
            }
        }
    }
    ll ans=1e18;
    for(int i = 1; i <= n; i++){
        for(auto vec : g[i]){
            ans=min({ans,dist[i-1]+vec.second/2+dist2[vec.first-1]});
        }
    }
    cout << ans << '\n';
}