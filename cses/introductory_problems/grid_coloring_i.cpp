#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i+j)%2==0){
                if(s[i][j]=='A'){
                    s[i][j]='B';
                }else{
                    s[i][j]='A';
                }
            }else{
                if(s[i][j]=='C'){
                    s[i][j]='D';
                }else{
                    s[i][j]='C';
                }
            }
        }
    }
    for(auto i : s){
        cout << i << '\n';
    }
}
