#include <bits/stdc++.h>
#define ll unsigned long long 
using namespace std;
int main(){
    string s,bad;
    int k;
    cin >> s >> bad >> k;
    int n=s.length();
    vector<bool> ok(26);
    for(int i = 0; i < 26; i++){
        ok[i]=(bad[i]=='1');
    }
    unordered_set<ll> ans; 
    for(int i = 0; i < n; i++){
        int bad=0;
        ll curr=0LL;
        for(int j = i; j < n; j++){
            if(!ok[s[j]-'a']){
                bad++;
            }if(bad>k){
                break;
            }
            curr=curr*83+(s[j]-'a'+1); 
            ans.insert(curr);
        }   
    }
    cout << ans.size() << '\n';
}