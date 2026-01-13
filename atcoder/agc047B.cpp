#include <bits/stdc++.h>
#define int long long 
using namespace std;
vector<vector<int>> cont;
struct node{
    int sons[26]={0};
    int cant=0;
    int isend=0;
    int ispreend=0;
};
vector<node> trie(1e6+5);
int ans=0;
int tot=-1;
int nods=1;
void insert(string& s){
    int nodoact=0;
    vector<int> cnt(26,0);
    for(int i = 0; i < s.length(); i++){
        int c=s[i]-'a';
        cnt[c]++;
        if(trie[nodoact].sons[c]==0){
            for(int j=0; j < 26; j++){
                trie[nods].sons[j]=0;
            }
            trie[nods].cant=0;
            trie[nods].isend=0;
            trie[nodoact].sons[c]=nods;
            nods++;
        }
        nodoact=trie[nodoact].sons[c];
        trie[nodoact].cant++;
        if(trie[nodoact].ispreend>0){
            for(int j = 0; j < 26; j++){
                if(trie[nodoact].sons[j]>0&&cont[tot][j]-cnt[j]>0){
                    ans += trie[trie[nodoact].sons[j]].isend;
                }
            }
        }

        if(i==s.length()-1){
            trie[nodoact].isend++;
        }
        if(i==s.length()-2){
            trie[nodoact].ispreend++;
        }
    }
}
int32_t main(){
    int n;
    cin >> n;
    cont.assign(n,vector<int>(26,0));
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),[&](string a, string b){
        if(a.length()==b.length()){
            return a<b;
        }
        return a.length() < b.length();
    });
    vector<int> one(26,0);
    for(int i =0 ; i < n; i++){
        tot++;
        string s = v[i];
        if(s.length()>1){
            for(auto c : s){
                cont[i][c-'a']++;
            }
            for(int j = 0; j < 26; j++){
                if(cont[i][j]){
                    ans+=one[j];
                }
            }
            reverse(s.begin(),s.end());
            insert(s);
        }else{
            ans+=one[s[0]-'a'];
            one[s[0]-'a']++;
        }
    }
    cout << ans << '\n';
}   