#include <bits/stdc++.h>
#define ll long long 
#define int long long 
#define f first 
#define s second
using namespace std;
vector<priority_queue<int>> best(2e5+5);
vector<vector<pair<int,int>>> g(2e5+5);
int32_t main(){
    int m, n,k ;
    cin >> m >> n>>k;
    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c; 
        g[a].push_back({b,c});
    }
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    best[1].push(0);
    pq.push({0,1});
    while(!pq.empty()){
        auto node=pq.top(); pq.pop();
        if(node.f>best[node.s].top()){
            continue;
        }
        for(auto nod : g[node.s]){
            if(best[nod.f].size()<k){
                best[nod.f].push(node.f+nod.s);
                pq.push({node.f+nod.second,nod.f});
            }else if(nod.s+node.f<best[nod.f].top()){
                best[nod.f].pop();
                best[nod.f].push(node.f+nod.s);
                pq.push({node.f+nod.s,nod.f});
            }
        }
    }
    vector<int> ans;
    while(!best[m].empty()){
        ans.push_back(best[m].top());
        best[m].pop();
    }
    reverse(ans.begin(),ans.end());
    for(auto i : ans){
        cout << i << ' ';
    }
}