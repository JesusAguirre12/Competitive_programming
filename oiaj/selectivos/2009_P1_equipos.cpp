#include <bits/stdc++.h>
#define int long long 
using namespace std;
void open(string name = ""){
    cin.tie(0)->sync_with_stdio(0); 
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

const int maxn=3e6;
struct trie{
    int sons[26];
    int cant;
};
int ans=-1;
string ans1;

int sz=-1;
int nods=1;
trie nodos[maxn];

void insert(string&s){
    int nodoact=0;
    for(int i = 0; i < s.length(); i++){
        int c=s[i]-'a';
        if(nodos[nodoact].sons[c]==0){
            for(int j=0; j < 26; j++){
                nodos[nods].sons[j]=0;
            }
            nodos[nods].cant=0;
            nodos[nodoact].sons[c]=nods;
            nods++;
        }
        nodoact=nodos[nodoact].sons[c];
        nodos[nodoact].cant++;
        int a=(i+1)*(i+1)*nodos[nodoact].cant;
        if(a>ans&&nodos[nodoact].cant>=2){
            sz=i+1;
            ans=a;
            ans1=s;
        }
    }
}

int32_t main(){
    open("equipo");
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        insert(s);
    }
    cout << ans << '\n' << ans1.substr(0,sz) << '\n';
}