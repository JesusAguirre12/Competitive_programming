#include <bits/stdc++.h>
#define ll long long 
#define sll(x) static_cast<ll>(x)
#define sz(x) sll(x.size())
using namespace std;
int main(){
    int n;
    cin >> n;
    int maxpot = sll(ceil(log2(n+2)));
    string s, abc = "aeiou";
    cin >> s;
    vector<vector<ll>> pos(n+1, vector<ll>(5,n+1));
    for(int i = n-1; i>=0; i--){
        if(i==n-1){
            pos[i][abc.find(s[i])]=sll(i);
            continue;
        }
        pos[i]=pos[i+1];
        pos[i][abc.find(s[i])]=i;
    }
    vector<ll> parent(n+1,-1);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 5; j++){
            parent[i]=max(parent[i],pos[i][j]);
        }
    }
    vector<vector<ll>> up(n+2, vector<ll>(maxpot+1,n+1));
    for(int i = 0; i <= n; i++){
        up[i][0]=parent[i];
        if(parent[i]!=n+1){
            up[i][0]++;
        }
    }
    for(int j = 1; j <= maxpot; j++){
        for(int i = 0; i <= n; i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        r++;
        int ans = 1;
        for(int i = maxpot; i>=0; i--){
            if(up[l][i]<r){
                l=up[l][i];
                ans+=(1<<i);
            }
        }
        cout << ans << '\n';
    }
}
