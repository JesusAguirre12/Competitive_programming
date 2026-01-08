#include <bits/stdc++.h>
#define int long long 
#define f first
#define s second
using namespace std;
void open(string name = ""){
    	cin.tie(0)->sync_with_stdio(0); 
    	freopen((name + ".in").c_str(), "r", stdin);
    	freopen((name + ".out").c_str(), "w", stdout);
}
int32_t main(){
    open("negocios");
    int n;
    cin >> n;
    vector<pair<pair<pair<int,int>,pair<int,int>>,int>> v(n);
    vector<int> perm(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].f.f.f >> v[i].f.f.s >> v[i].f.s.f >> v[i].f.s.s;
        v[i].s=i+1;
    }
    sort(v.begin(),v.end(), [&](pair<pair<pair<int,int>,pair<int,int>>,int> a, pair<pair<pair<int,int>,pair<int,int>>,int> b){
        return a.f.s.f<b.f.s.f;
    });
    vector<int> dp(n,-1e9);
    vector<int> parent(n,-1);
    
    for(int i = 0; i < n; i++){
        if(abs(v[i].f.f.f)+abs(v[i].f.f.s) <= v[i].f.s.f){
            dp[i]=v[i].f.s.s;
        }
        for(int j = 0; j < i; j++){
            if(dp[j]<0){
                continue;
            }
            if(v[j].f.s.f+3+abs(v[j].f.f.f-v[i].f.f.f)+abs(v[j].f.f.s-v[i].f.f.s) <= v[i].f.s.f){
                if(dp[i]<dp[j]+v[i].f.s.s){
                    dp[i]=dp[j]+v[i].f.s.s;
                    parent[i]=j;
                }
            }
        }
    }
    int ans=0;
    int idx=-1;
    for(int i = 0; i < n; i++){
        if(dp[i]>ans){
            ans=dp[i];
            idx=i;
        }
    }
    cout<< ans << '\n';
    vector<int> path;
    while(idx!=-1){
        path.push_back(v[idx].s);
        idx=parent[idx];
    }
    reverse(path.begin(),path.end());
    for(auto el : path){
        cout<<el<<' ';
    }
}
