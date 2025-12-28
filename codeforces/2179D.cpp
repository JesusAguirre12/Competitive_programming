#include <bits/stdc++.h>
#define int long long 
#define f first
#define s second
using namespace std;
int32_t main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int mx = -1;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mx=max(mx,v[i]);
    }
    vector<vector<int>> ans(mx+1);
    if(mx>=1){
        ans[1] = {1,0};
        for(int i = 2; i <= mx; i++){
            for(int j = 0; j < ans[i-1].size(); j++){
                //cout << "ADDING " << (ans[i-1][j]<<1|1) << " to " << i << '\n';
                ans[i].push_back(ans[i-1][j]<<1|1);
            }
            for(int j = 0; j < (1<<(i-1)); j++){
                //cout << "ACAAAA";
                ans[i].push_back(j<<1);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < ans[v[i]].size(); j++){
            cout << ans[v[i]][j] << ' ';
            //cout << "--------------------------" << v[i] << '\n';
        }
        cout << '\n';
    }
}