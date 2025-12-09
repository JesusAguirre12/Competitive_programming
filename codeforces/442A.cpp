#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    unordered_set<string> s;
    for(auto i : v){
        s.insert(i);
    }
    string c="RGBYW";
    string m="12345";
    int ans=100000;
    for(int i = 0; i <= 1<<5; i++){
        for(int j = 0; j <= 1<<5; j++){
            unordered_set<string> mark;
            bool ok =1;
            for(auto el : s){
                string cur;
                bool ok1=0,ok2=0;
                for(int k = 0; k < 5; k++){
                    if(i&(1<<k) && el[0]==c[k]){
                        cur.push_back(el[0]);
                        ok1=1;
                    }
                    
                }
                if(!ok1){
                    cur.push_back('&');
                }
                for(int k = 0; k < 5; k++){
                    if(j&(1<<k) && el[1]==m[k]){
                        cur.push_back(el[1]);
                        ok2=1;
                    }
                    
                }
                if(!ok2){
                    cur.push_back('&');
                }
                if(mark.count(cur)){
                    ok=0;
                    break;
                }
                mark.insert(cur);
            }
            if(ok){
                ans=min((int32_t)ans,__builtin_popcount(i)+__builtin_popcount(j));
            }
        }
    }
    cout << ans << '\n';
}