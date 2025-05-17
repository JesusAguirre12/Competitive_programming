#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m);
    vector<long long> w(m);
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
    }
    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(n, 0);
    vector<int> parent(n, -1);
    int x = -1;
    for(int i = 0; i < n; i++){
        x=-1;
        for(int j = 0; j < m; j++){
            if(dist[u[j]]+w[j]<dist[v[j]]){
                dist[v[j]]=dist[u[j]]+w[j];
                parent[v[j]]=u[j];
                x = v[j];
            }
        }
    }
    if(x == -1){
        cout << "NO\n";
    }else{
        int y = x;
        for(int i = 0; i < n; i++) y = parent[y];
        vector<int> cycle;
        for(int cur = y;; cur = parent[cur]){
            cycle.push_back(cur);
            if(cur == y && cycle.size()>1) break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES\n";
        for(int v : cycle) cout << v+1 << ' ';
        cout << '\n';
    }
    return 0;
}
