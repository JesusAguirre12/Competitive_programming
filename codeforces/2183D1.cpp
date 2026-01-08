#include <bits/stdc++.h>
#define int long long 
using namespace std; 
void open(string name = ""){
    	cin.tie(0)->sync_with_stdio(0); 
    	freopen((name + ".in").c_str(), "r", stdin);
    	freopen((name + ".out").c_str(), "w", stdout);
}
struct nods{
    int prof,sons;
};
int32_t main(){
    //open("prob");
    int t;
    cin >> t;
    while(t--){ 
        int n;
        cin >> n;
        vector<vector<int>> g(n+1);
        map<int,int> mp;
        for(int i = 1; i < n; i++){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<nods> inf(n+1,{-1,0});
        int maxp=0;
        vector<int> visited(n+1,0);
        queue<int> q;
        inf[1].prof=0;
        q.push(1);
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto nod : g[node]){
                //cout << inf[nod].prof << '\n';
                if(inf[nod].prof<0){
                    inf[nod].prof=inf[node].prof+1;
                    //cout << inf[nod].prof << '\n';
                    inf[node].sons++;
                    q.push(nod);
                }
            }
        }
        int m=0,ans1=0;
        for(int i = 1; i <= n; i++){
            mp[inf[i].prof]++;
            //cout << inf[i].prof << ' ' << inf[i].sons << '\n';
            m=max(m,inf[i].prof);
            ans1=max(ans1,inf[i].sons);
        }
        int ans2=0;
        bool ok=0;
        for(int i = 0; i <= m; i++){
            if(mp[i]>ans2){
                ok=1;
                ans2=mp[i];
            }
        }
        cout << max(ans2,ans1+1)<< '\n';
    }
}