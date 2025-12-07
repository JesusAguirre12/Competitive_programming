//100 pts
#include <bits/stdc++.h>
using namespace std;
void open(string name = ""){
    cin.tie(0)->sync_with_stdio(0); 
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main(){
    open("latas");
    int n;
    cin>> n;
    int tot=0;
    vector<vector<int>> mat(n+1,vector<int>(n+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i+1; j++){
            cin >> mat[i][j];
            tot+=mat[i][j];
        }
    }
    vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pref[i][j] = pref[i][j-1]+pref[i-1][j]+mat[i][j]-pref[i-1][j-1];
        }
    }
    vector<int> tri(n+1,0);
    for(int i = 1; i < n; i++){
        tri[i]+=tri[i-1];
        for(int j = 0; j < i; j++){
            tri[i]+=mat[n-i+j+1][n-j];
        }
    }
    int ans = 1e9+1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int prev=(tot-tri[max(n-i-j+1,0)]-pref[i-1][n]-pref[n][j-1]+pref[i-1][j-1]);
            ans=min(ans,tot-prev);
        }
    }
    cout << ans << '\n';
}