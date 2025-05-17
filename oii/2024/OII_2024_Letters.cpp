//100 pts
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    string s, abc = "aeiou";
    cin >> n >> s >> q;
    vector<vector<int>>pos(n+1,vector<int>(5,n));
    for(int i = n-1; i >= 0; i--){
        pos[i]=pos[i+1];
        pos[i][abc.find(s[i])]=i;
    }
    /*for(int i = 0; i < n+1; i++){
        for(int j = 0; j < 5; j++){
            cout << pos[i][j] << ' ';
        }
        cout << '\n';
    }*/
    // cout << '\n';
    int maxpot=0;
    for(int i = 1; i < 31; i++){
        if((1<<i) > (n+2)){
            maxpot=i;
            break;
        }
    }
    // cout << maxpot << '\n';
    vector<int> parent(n+1,-1);
    for(int i = 0; i <= n; i++){
        for(auto j : pos[i]){
            parent[i]=max(parent[i],j);
        }
        parent[i]++;
    }
    /*
    for(auto i : parent){
        cout << i << ' ';
    }
    cout << '\n' << '\n';
    */
    vector<vector<int>> ancestro(n+2, vector<int>(maxpot,n+1));
    for(int i = 0; i <= n; i++) ancestro[i][0] = parent[i];
    for(int j = 1; j <= maxpot; j++)
        for(int i = 0; i <= n; i++)
            ancestro[i][j] = ancestro[ancestro[i][j-1]][j-1];
    /*
    for(int j = 0; j <= maxpot; j++){
        for(int i = 0; i <= n; i++){
            cout << ancestro[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    while(q--){
        int a,b;
        cin >> a >> b;
        int ans=1, act=a-1;
        for(int i = maxpot-1; i >= 0; i--){
            if(ancestro[act][i] < b+1){
                act=ancestro[act][i];
                ans+=(1<<i);
            }
        }
        cout << ans << '\n';
    }

}