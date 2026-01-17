#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree(2e3+5,vector<int>(2e3+5,0));
int n,m;
vector<string> mat;
void build(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j]=='*'){
                tree[n+i][m+j]=1; 
            }
        }
        for(int j = m-1; j > 0; j--){
            tree[i+n][j]=tree[i+n][j<<1]+tree[i+n][j<<1|1];
        }
    }
    for(int i = n-1; i > 0; i--){
        for(int j = 2*m-1; j > 0; j--){
            tree[i][j]=tree[i<<1][j]+tree[i<<1|1][j];
        }
    }
}
void update(int val, int x, int y){
    x+=m;
    y+=n;   
    tree[y][x]=val;
    for(int j = x>>1; j > 0; j>>=1){
        tree[y][j]=tree[y][j<<1]+tree[y][j<<1|1];
    }
    for(int i = y>>1; i > 0; i >>=1){
        for(int j = x; j > 0; j>>=1){
            tree[i][j]=tree[i<<1][j]+tree[i<<1|1][j];
        }
    }
}
 
int query(int x1, int y1, int x2, int y2){
    y1+=n;
    y2+=n;
    x1+=m;
    x2+=m;
    int ans=0;
    while(y1<y2){
        if(y1&1){
            int xx1=x1;
            int xx2=x2;
            while(xx1<xx2){
                if(xx1&1){
                    ans+=tree[y1][xx1++];
                }
                if(xx2&1){
                    ans+=tree[y1][--xx2];
                }
                xx1>>=1;
                xx2>>=1;
            }
            y1++;
        }
        if(y2&1){
            int xx1=x1;
            int xx2=x2;
            y2--;
            while(xx1<xx2){
                if(xx1&1){
                    ans+=tree[y2][xx1++];
                }
                if(xx2&1){
                    ans+=tree[y2][--xx2];
                }
                xx1>>=1;
                xx2>>=1;
            }
        }
        y2>>=1;
        y1>>=1;
    }
    return ans;
}
int main(){
    int q;
    cin >> n >> q;
    m=n;
    mat.resize(n);
    for(int i = 0; i < n; i++){
        cin >> mat[i];
    }
    build();
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            mat[x][y]=(mat[x][y]=='*'?'.':'*');
            update((mat[x][y]=='*'? 1:0),y,x);
        }else{
            int x1,y1,x2,y2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << query(--x1,--y1,x2,y2);
            cout << '\n';
        }
    }
}