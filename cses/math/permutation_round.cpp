#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod=1e9+7;
vector<pair<ll,int>> fact(ll x){
    vector<pair<ll,int>> ans;
    for(ll i = 2; i*i <= x; i++){
        if(x%i==0){
            int cnt=0;
            while(x%i==0){
                x/=i;
                cnt++;
            }   
            ans.push_back({i,cnt});
        }
    }
    if(x>1){
        ans.push_back({x,1});
    }
    return ans;
}

int32_t main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        g[i].push_back(x-1);
    }
    vector<int> ci;
    vector<int> visited(n,0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            int sz=0;
            while(!q.empty()){
                int nod=q.front();q.pop();
                if(visited[nod]){
                    continue;
                }
                visited[nod]=1;
                sz++;
                for(auto v: g[nod]){
                    q.push(v);
                }
            }
            ci.push_back(sz);
        }
    }
    ll ans=1LL;
    map<int,int> mp;
    for(auto el : ci){
        auto desc=fact(el);
        for(auto i : desc){
            mp[i.first]=max(i.second,mp[i.first]);
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        for(int j = 0; j < it->second; j++){
            ans*=(it->first);
            ans%=mod;
        }
    }
    cout << ans << '\n';
}