#include <bits/stdc++.h>
using namespace std;
#define val(x) get<0>(x)
#define lc(x) get<1>(x)
#define rc(x) get<2>(x)
vector<tuple<int,int,int>> tree;
vector<int> sz;
int build(vector<int>&v){
    int n = v.size();
    vector<int> st;
    tree.assign(n, {0, -1, -1});
    for(int i = 0; i < n; i++){
        lc(tree[i])=-1;
        rc(tree[i])=-1;
        val(tree[i])=v[i];
        int curr=-1;
        while(!st.empty() && v[i]<v[st.back()]){
            curr=st.back();
            st.pop_back();
        }
        if(!st.empty()){
            rc(tree[st.back()])=i;
        }
        lc(tree[i])=curr;
        st.push_back(i);
    }
    return st.empty() ? -1 : st.front();
}
int buildsz(int nod){
    if(nod==-1){
        return 0;
    }
    sz[nod]=buildsz(lc(tree[nod]))+buildsz(rc(tree[nod]))+1;
    return sz[nod];
}
int solve(int nod, int hor=0){
    if(nod==-1){
        return 0;
    }
    int co=val(tree[nod]);
    return min(sz[nod], solve(lc(tree[nod]), co) + solve(rc(tree[nod]), co) + co-hor);
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    } 
    int root = build(v);
    sz.assign(n,0);
    buildsz(root);
    cout << solve(root,0);
}