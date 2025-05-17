#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> cnt(26,0);
    for(char c : s) {
        cnt[c-'A']++;
    }
    string ans;
    ans.reserve(n);
    int prev = -1;  
    for(int i = 0; i < n; i++){
        bool placed = 0;
        int rem = n-i-1;           
        int lim = (rem+1)/2;   
        for(int c = 0; c < 26; c++){
            if(c == prev || cnt[c] == 0) continue;
            cnt[c]--;
            int mx=0;
            for(int k = 0; k < 26; k++){
                mx = max(mx, cnt[k]);
            }
            if(mx <= lim){
                ans.push_back(char('A'+c));
                prev = c;
                placed = 1;
                break;
            }else{
                cnt[c]++;
            }
        }
        if(!placed){
            cout << -1;
            return 0;
        }
    }
 
    cout << ans;
    return 0;
}