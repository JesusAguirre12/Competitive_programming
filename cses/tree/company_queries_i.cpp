#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> parent(n+1,vector<int>(20,-1));
    parent[1][0]=-1;
    for(int i=2; i <= n; i++){
        cin>>parent[i][0];
    }
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            if(parent[j][i-1] == -1){
                parent[j][i]=-1;
            }else{
                parent[j][i]=parent[parent[j][i-1]][i-1];
            }
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        for(int i = 0; i < 20; i++){
            if(b&(1<<i)){
                a=parent[a][i];
                if(a==-1){
                    break;
                }
            }
        }
        cout << a << '\n';
    }
}