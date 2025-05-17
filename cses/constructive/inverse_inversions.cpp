#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin >>  n >> k;
    unordered_map<long long,long long>mp;
    for(int i = n-1; i >= 0; i--){
        if(i<k){
            mp[i+1]=n-1-i;
            k-=i;
        }else if(i>=k){
            mp[i+1]=n-i-1+(i-k);
            break;
        }
    }
    vector<int> ans(n,0);
    for(auto&i:mp){
        ans[i.second]=i.first;
    }
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(ans[i]==0){
            ans[i]=++idx;
        }
    }
    for(auto&i:ans){
        cout << i << '\n';
    }
}