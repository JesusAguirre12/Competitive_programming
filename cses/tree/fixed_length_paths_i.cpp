#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
ll ans=0;
vector<vector<int>> g(2e5+5);
vector<int> sz(4e5+5);
vector<bool> used(2e5+5);
vector<int> dist;
vector<int> dist1(2e5+5);
void dfs_tam(int node, int pa){
    sz[node]=1;
    for(auto nod : g[node]){
        if(used[nod] || nod == pa){
            continue;
        }
        dfs_tam(nod,node);
        sz[node]+=sz[nod];
    }
}
int dfs_centroide(int node, int pa, int tot){
    for(auto nod: g[node]){
        if(used[nod]||nod == pa){
            continue;
        }
        if(sz[nod]>(tot>>1)){
            return dfs_centroide(nod,node,tot);
        }
    }
    return node;
}
void dfs_calc(int node, int pa, int currdist){
    if(currdist>k){
        return;
    }
    dist.push_back(currdist);
    for(auto nod : g[node]){
        if(used[nod]||nod == pa){
            continue;
        }
        dfs_calc(nod,node,currdist+1);
    }
}
void solve_c(int c){
    int maxd=0;
    dist1[0]=1;
    for(auto nod : g[c]){
        if(used[nod]) continue;
        dist.clear();
        dfs_calc(nod,c,1);
        for(auto el : dist){
            if(k-el>=0){
                ans+=dist1[k-el];
            }
        }
        for(auto el : dist){
            dist1[el]++;
            maxd=max(maxd,el);
        }
    }
    for(int i = 0; i <= maxd; i++){
        dist1[i]=0;
    }
}
void solve(int start){
    dfs_tam(start, -1);
    int c = dfs_centroide(start, -1, sz[start]);
    solve_c(c);
    used[c] = 1;
    for(auto nod : g[c]){
        if(!used[nod]){
            solve(nod);
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve(0);
    cout << ans << '\n';
}
