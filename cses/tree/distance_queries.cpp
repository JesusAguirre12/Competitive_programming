#include <bits/stdc++.h>
#define ll long long 
using namespace std;
vector<vector<int>> parent(2e5+3,vector<int>(20,-1));
vector<int> prof(2e5+3,0);
vector<vector<int>> g(2e5+3);
void dfs(int node, int pa){
    parent[node][0]=pa;
    for(auto &i:g[node]){
        if(i==pa){
            continue;
        }
        prof[i]=prof[node]+1;
        dfs(i,node);
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int a,b;
        cin >>a>> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    prof[1]=0;
    
    dfs(1,-1);
    for(int j = 1; j < 20; j++){
        for(int i = 2; i <= n; i++){
            if(parent[i][j-1]!=-1){
                parent[i][j]=parent[parent[i][j-1]][j-1];
            }
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        if(prof[a]<prof[b]) swap(a,b);
        ll ans=0;
        for(int i = 19; i >= 0; i--){
            if(parent[a][i] != -1 && prof[parent[a][i]] >= prof[b]){
                a=parent[a][i];
                ans+=(1<<i);
            }
        }
        if(a==b){
            cout << ans << '\n';
            continue;
        }
        for(int i = 19; i >= 0; i--){
            if(parent[a][i] != -1 && parent[b][i] != parent[a][i]){
                ans+=(1<<(i+1));
                a=parent[a][i];
                b=parent[b][i];
            }
        }
        ans+=2;
        cout << ans << '\n';
    }
}