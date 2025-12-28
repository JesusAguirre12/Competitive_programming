#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1);
    for (int i = 0; i < m; i++){
        int a,b,c;
        cin >>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    vector<bool> vis(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    int ans = 0;
    int cnt = 0;
    while(!pq.empty()){
        auto [c,nod] = pq.top();pq.pop();
        if (vis[nod]) continue;
        vis[nod]=1;
        ans+=c;
        cnt++;
        for(auto &[nodo,c2] : g[nod]){
            if(!vis[nodo]){
                pq.push({c2,nodo});
            }
        }
    }
    if(cnt != n){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << ans << '\n';
    }
}
