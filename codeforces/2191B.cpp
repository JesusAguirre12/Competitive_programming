#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mp;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin>>v[i];
            mp[v[i]]++;
        }
        if(!mp[0]){
            cout << "NO\n";
        }else if(mp[0]==1){
            cout << "YES\n";
        }else if(mp[1]>0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }
}