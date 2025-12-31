#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll inf = LLONG_MAX;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
    }
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0LL,1});
    vector<ll> dist(n+1, 1e18), minc(n+1, 1e18), maxc(n+1, -1), totc(n+1, 0);
    dist[1]=0;
    totc[1]=1;
    maxc[1]=0;
    minc[1]=0;
    vector<bool> visited(n+1,0);
    while(!pq.empty()){
        ll node = pq.top().second, cost=pq.top().first;
        pq.pop();
        if(cost>dist[node]){
            continue;
        }
        for(auto & [nod, val] : g[node]){
            if(dist[node]+val < dist[nod]){
                dist[nod]=dist[node]+val;
                minc[nod]=minc[node]+1;
                maxc[nod]=maxc[node]+1;
                totc[nod]=totc[node];
                pq.push({dist[nod],nod});
            }
            else if(dist[node]+val==dist[nod]){
                totc[nod]=totc[nod]+totc[node];
                totc[nod]%=(int)(1e9+7);
                minc[nod]=min(minc[nod],minc[node]+1);
                maxc[nod]=max(maxc[nod],maxc[node]+1);
            }
        }
    }
    cout << dist[n] << ' ' << totc[n] << ' ' << minc[n] << ' ' << maxc[n] << '\n';
}