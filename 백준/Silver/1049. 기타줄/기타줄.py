import sys
import math

n, m = map(int, input().split(' '))
a = []
b = []
for i in range(m):
    j, k = map(int, sys.stdin.readline().split(' '))
    a.append(j)
    b.append(k)

a.sort()
b.sort()
aprice = a[0]
bprice = b[0] 

price = []

lineall = aprice * int(math.ceil(n/6))
linenum = aprice*(n//6) + bprice*(n%6)
liness = bprice*n

price = [lineall, linenum, liness]
price.sort()



print(price[0])