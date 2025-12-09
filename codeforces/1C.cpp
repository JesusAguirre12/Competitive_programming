#include <bits/stdc++.h>
#define int long long
#define pi 3.14159265359
#define ld long double
using namespace std;
ld norm(ld ang){
    while(ang < 0){
        ang += 2*pi;
    }
    while(ang >= 2*pi){
        ang -= 2*pi;
    }
    return ang;
}
int32_t main(){
    ld ax,ay,bx,by,cx,cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    //////
    ax+=1000;
    ay+=1000;
    bx+=1000;
    by+=1000;
    cx+=1000;
    cy+=1000;
    ///////
    ld A = 2*(ax-bx);
    ld B = 2*(ay-by);
    ld C = (ax*ax-bx*bx)+(ay*ay-by*by);
    ld E = 2*(ax-cx);
    ld F = 2*(ay-cy);
    ld D = (ax*ax-cx*cx)+(ay*ay-cy*cy);
    /////
    ld x = (C*F - B*D) / (A*F - E*B);
    ld y = (A*D - C*E) / (A*F - E*B);
    //cout << "punto: " << x << ' ' << y << '\n'
    ld r = hypotl(x-ax, y-ay);
    ld t1=norm(atan2l(ay-y,ax-x));
    ld t2=norm(atan2l(by-y,bx-x));
    ld t3=norm(atan2l(cy-y,cx-x));
    //cout << "->>> t: " << t1<< ' ' << ' ' << t2 << ' ' << t3 << '\n';
    ld d1 = t2-t1;
    ld d2 = t3-t2;
    ld d3 = t1+2*pi-t3;
    //cout<< "--->>> d: " << d1 << ' '<< d2 << ' ' << d3 << '\n';
    for(int n = 3; n <= 100; n++){
        int k1 = llround(d1/(2*pi/n));
        int k2 = llround(d2/(2*pi/n));
        int k3 = llround(d3/(2*pi/n));
        //cout << "ACAAAA";
        //cout << "--> k: " << k1 << ' ' << k2 << ' ' << k3 << '\n';
        if(fabsl(d1-k1*(2*pi/n))< 1e-6L and fabsl(d2-k2*(2*pi/n)) < 1e-6L and fabsl(d3-k3*(2*pi/n)) < 1e-6L){
            //cout << "HERE";
            if(k1+k2+k3==n){
                //cout << "HERE";
                //cout << n << '\n';
                cout<<fixed << setprecision(6)<< (ld)(0.5L*(ld)(n)*sinl((ld)(2.0*pi/(ld)(n)))*(r*r));
                return 0;
            }
        }
    }
}