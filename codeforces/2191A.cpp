#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            cin >>v[i].first;
            v[i].second=i%2; 
        }
        sort(v.begin(), v.end());
        bool ok=1;
        for(int i = 0; i < n-1; i++){
            if (v[i].second==v[i+1].second){
                ok = 0;
                break;
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}