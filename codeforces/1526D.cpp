#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    int t;
    cin>> t;
    while(t--){
        string s;
        cin>> s;
        string conv="ANOT";
        string ans=conv;
        int ans1=-1;
        unordered_map<char,int> mp;
        mp['A']=0;
        mp['N']=1;
        mp['O']=2;
        mp['T']=3;
        vector<int> cont(4,0);
        for(auto i : s){
            cont[mp[i]]++;
        }
        do{
            vector<int> ap(4,0),cnt(4,0);
            int curr=0;
            for(int i = 0; i < 4; i++){
                ap[mp[conv[i]]]=i;
            }/*
            for(auto i : ap){
                cout << i << ' ';
            }
            cout << '\n';*/
            for(auto c: s){
                for(int i = 0; i < 4; i++){
                    if(ap[mp[c]]<ap[i]){
                        curr+=cnt[i];
                    }
                }
                cnt[mp[c]]++;
            }
            /*
            for(auto i : cnt){
                cout << i << ' ';
            }*/
            //cout << '\n';
            //cout << conv << ' ' << curr << '\n';
            if(curr>ans1){
                ans=conv;
                ans1=curr;
            }
        }while(next_permutation(conv.begin(),conv.end()));
        for(auto i: ans){
            for(int j= 0; j < cont[mp[i]]; j++){
                cout << i;
            }
        }
        cout << '\n';
    }
}