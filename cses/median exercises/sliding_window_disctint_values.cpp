#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for(auto&i:v)cin >> i;
    unordered_map<int, int> freq;
    auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b){
        if(a.first != b.first)return a.first>b.first; 
        return a.second<b.second;
    };
    set<pair<int,int>, decltype(cmp)> s(cmp); 
    auto insert = [&](int x){
        int f = freq[x]++;
        if(f>0)s.erase({f,x});
        s.insert({f+1,x});
    };
    auto erase=[&](int x){
        int f=freq[x]--;
        s.erase({f,x});
        if(freq[x]>0) s.insert({f-1, x});
    };
    for(int i = 0; i < k; i++)insert(v[i]);
    cout << s.size() << '\n';
    for(int i = k; i < n; i++){
        erase(v[i-k]);
        insert(v[i]);
        cout << s.size()<< '\n';
    }
}