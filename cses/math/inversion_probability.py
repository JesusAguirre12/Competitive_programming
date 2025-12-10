from decimal import Decimal, getcontext
getcontext().prec=40
def f(n, r):
    inv = Decimal(0)
    for a in range(n):
        for b in range(a+1, n):
            r_a, r_b = r[a], r[b]
            cont = sum(1 for x_a in range(1, r_a+1) for x_b in range(1,r_b+1) if x_a>x_b)
            inv+= Decimal(cont)/(r_a*r_b)
    return inv
 
n = int(input())
r = list(map(int,input().split()))
ans = f(n,r)
print(f"{ans:.6f}")