#include <bits/stdc++.h>
using namespace std;
struct node{
    int sons[10]={0};
    int cant=0;
    bool isend=0;
};
vector<node> trie(3e6);

int nods=1;
bool insert(string& s){
    int nodoact=0;
    for(int i = 0; i < s.length(); i++){
        int c=s[i]-'0';
        if(trie[nodoact].sons[c]==0){
            for(int j=0; j < 10; j++){
                trie[nods].sons[j]=0;
            }
            trie[nods].cant=0;
            trie[nods].isend=0;
            trie[nodoact].sons[c]=nods;
            nods++;
        }
        nodoact=trie[nodoact].sons[c];
        trie[nodoact].cant++;
        if(trie[nodoact].isend==1 || i==s.length()-1 && trie[nodoact].cant>1){
            return 0;
        }
        if(i==s.length()-1){
            trie[nodoact].isend=1;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        auto ans="YES\n";
        bool found=0;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(!found){
                if(!insert(s)){
                    ans="NO\n";
                    found=1;
                }
            }
        }
        cout << ans;
        trie=vector<node>(3e6); 
        nods=1;                     
    }
}