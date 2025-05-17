n=int(input())
xx=[]
yy=[]
tot1=0
tot2=0
for _ in range(n):
    a, b = map(int, input().split())
    xx.append(a)
    yy.append(b)
    tot1 += a
    tot2 += b
xx.sort()
yy.sort()
x=0
y=0
for i in range(n-1):
    x += tot1-(n-i)*xx[i]
    y += tot2-(n-i)*yy[i]
    tot1 -= xx[i]
    tot2 -= yy[i]
 
print(x+y)