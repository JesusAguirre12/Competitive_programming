#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mp;
        string s;
        cin >> s;
        for(auto i : s){
            mp[i-'0']++;
        }
        auto s2=s;
        sort(s2.begin(),s2.end());
        if(s==s2){
            cout << "Bob\n";
            continue;
        }else{
            cout << "Alice\n";
            vector<int> v;
            for(int i = 0; i < n; i++){
                if((s[i]-'0')&1 && i<mp[0] || s[i]=='0' && i>=mp[0]){
                    v.push_back(i);
                }
            }
            cout << v.size() << '\n';
            for(auto i : v){
                cout << ++i << ' ';
            }
            cout << '\n';
        }
    }
}