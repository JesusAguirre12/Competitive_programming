#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
vector<vector<int>> g(2e5+5);
vector<int> parimp(2e5+5,0); 
int32_t main(){
    int n;
    cin >> n;
    queue<pair<int,int>> q1,q2;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(i+1-a>0){
            g[i+1-a].push_back(i+1);
        }
        if(a+i+1<=n){
            g[i+1+a].push_back(i+1);
        }
        if(a&1){
            q1.push({0,i+1});
            parimp[i+1]=1;
        }else{
            q2.push({0,i+1});
        }
    }
    vector<int> dp1(2e5+5,1e9), dp2(2e5+5,1e9);
    while(!q1.empty()){
        auto node=q1.front();q1.pop();
        for(auto nod : g[node.s]){
            
            if(dp1[nod]>node.f+1 && !parimp[nod]){
                dp1[nod]=node.f+1;
                q1.push({dp1[nod],nod});
            }
        }
    }
    while(!q2.empty()){
        auto node=q2.front();q2.pop();
        for(auto nod : g[node.s]){
            if(dp2[nod]>node.f+1 && parimp[nod]){
                dp2[nod]=node.f+1;
                q2.push({dp2[nod],nod});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!parimp[i]){
            cout << (dp1[i]==1e9?-1:dp1[i]);
        }else{
            cout << (dp2[i]==1e9?-1:dp2[i]);
        }
        cout << ' ';
    }
}
