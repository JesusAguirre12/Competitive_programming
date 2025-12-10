//100 pts
#include <bits/stdc++.h>
using namespace std;
int query(int s, int t);
int answer(int i, int a);
void solve(int N){
    if(N==1){
        answer(1,1);
        return;
    }else if(N==2){
        answer(1,1);
        answer(2,2);
        return;
    }
    int n=N;
    vector<int> diff1, diff2;
    for(int i = 0; i < n-1; i++){
        diff1.push_back(query(i+1,i+2));
        if(i<n-2){
            diff2.push_back(query(i+1,i+3));
        }
    }
    vector<int> ans1(n,0);
    vector<int> ans2(n,0);
    ans1[0]=-1;
    ans2[0]=1; //esto nos dice hacia donde apunta el signo, corte  si es positivo, va asi i < i+1 (es determinante de i+1)
    for(int i = 0; i < n-2; i++){
        if(diff1[i]+diff1[i+1]==diff2[i]){
            ans1[i+1]=ans1[i];
            ans2[i+1]=ans2[i];
        }else{
            ans1[i+1]=-ans1[i];
            ans2[i+1]=-ans2[i];
        }
    }
    /*for(int i = 0; i < n; i++){
        cout << ans2[i] << ' ';
    }*/
    /*cout << '\n';*/
    vector<int>ans(n,0);
    for(int i = 0; i < n-1; i++){
        ans[i+1]=ans[i]+diff1[i]*ans1[i];
    }/*
    for(int i = 0; i < n; i++){
        cout << diff1[i] << '\n';
    }*/
    int minnn=1e9, minpos=-1, maxx=-1e9, maxpos=-1;
    for(int i = 0; i < n; i++){
        if(ans[i]<minnn){
            minnn=ans[i];
            minpos=i;
        }if(ans[i]>maxx){
            maxx=ans[i];
            maxpos=i;
        }
    }
    if(minpos>maxpos){
        ans[0]=0;
        for(int i = 0; i < n-1; i++){
            //cout <<"->" << ans[i] << ' ' << ans2[i+1] << ' ' << diff1[i] << '\n';
            ans[i+1]=ans[i]+diff1[i]*ans2[i];
            //cout << "seteando a " << ans[i+1] << '\n';
        }
    }
    int minn=1e9;
    for(int i = 0; i < n; i++){
        minn=min(ans[i],minn);
    }
    for(int i = 0; i < n; i++){
        ans[i]+=-1*(minn)+1;
    }
    for(int i = 0; i < n; i++){
        answer(i+1,ans[i]);
    }
}