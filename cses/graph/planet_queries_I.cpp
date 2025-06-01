#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> ancestro(n+2, vector<int>(31,0));
    for(int i = 1; i <= n; i++){
        cin >> ancestro[i][0];
    }
    for(int j = 1; j < 31; j++){
        for(int i = 0; i <= n; i++){
            ancestro[i][j] = ancestro[ancestro[i][j-1]][j-1];
        }
    }
    while(q--){
        int x, k;
        cin >> x >> k;
        for(int i = 0; i < 31; i++){
            if(k&(1<<i)){x = ancestro[x][i];}
        }
        cout << x << '\n';
    }
