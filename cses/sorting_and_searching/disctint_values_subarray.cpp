#include <bits/stdc++.h>
#define ll long long 
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main(){
    unordered_set<int,custom_hash> s;
    ll ans = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto&i:v){cin>>i;}
    int l = 0;
    for(int r = 0; r < n; r++){
        if(s.find(v[r])!=s.end()){
            while(l<r){
                if(s.find(v[r])!=s.end()){
                    s.erase(v[l]);
                    l++;
                }else{
                    break;
                }
            }
        }
        s.insert(v[r]);
        ans+=(r-l+1LL);
    }
    cout << ans;
}