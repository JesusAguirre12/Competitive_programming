#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans=0;
vector<vector<int>> g(5e4+5);
vector<int> sz(5e4+5);
vector<bool> used(5e4+5);

vector<int> tree;
int m;

void update(int p, int val){
    p+=m;
    tree[p]+=val;
    for(p>>=1;p>0;p>>=1){
        tree[p]=tree[p<<1]+tree[p<<1|1];
    }
}
int query(int l, int r){
    l+=m;
    r+=m;
    int cans =0;
    while(l<r){
        if(l&1){cans+=tree[l++];}
        if(r&1){cans+=tree[--r];}
        l>>=1;
        r>>=1;
    }
    return cans;
}


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
void dfs_calc(int node, int pa, int currdist, vector<int>&dist){
    if(currdist>k){
        return;
    }
    dist.push_back(currdist);
    for(auto nod : g[node]){
        if(used[nod]||nod == pa){
            continue;
        }
        dfs_calc(nod,node,currdist+1,dist);
    }
}
void solve_c(int c){
    m=k+1;
    tree.assign(m<<1,0);
    update(0,1);
    for(auto nod : g[c]){
        if(used[nod]) continue;
        vector<int> dist;
        dfs_calc(nod,c,1,dist); 
        for(auto el : dist){
            if(k-el>=0){
                ans += query(k-el,k-el+1);
            }
        }
        for(auto el : dist){
            update(el,1);
        }
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