#include <bits/stdc++.h>
#pragma GCC optimize("fast-math,Ofast,unroll-all-loops")
#pragma GCC target("sse,sse2")
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> sq(3164);
    for(int i = 0; i <= 3163; i++){
        sq[i] = i*i;
    }
    unordered_map<int,pair<int,int>> mp;
    mp.reserve(10000000/2);
    for(int i = 0; i <= 3163; i++){
        for(int j = i; j <= 3163; j++){
            int s = sq[i]+sq[j];
            if(s>10000000){
                break;
            }
            if(!mp.count(s)){
                mp[s]={i,j};
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        bool ok=1;
        for(int i = 0; i <= 3163 && ok; i++){
            for(int j = i; j <= 3163 && ok; j++){
                int s = sq[i]+sq[j];
                if(s>n){
                    break;
                }
                if(mp.count(n-s)){
                    auto [a,b]=mp[n-s];
                    cout << i << ' ' << j << ' ' << a << ' ' << b << '\n';
                    ok=0;
                    break;
                }
            }
        }
    }
}
