from random import *
import sys
a = ["insert", "delete", "exists", "next", "prev"]
sys.stdout = open("in.txt", "w")
ans = []
n = 5
boo = [False] * (n + 1)
for i in range(20):
    j = randint(0, 4)
    s = a[j]
    k = randint(0, n)
    print(s, k)
    if j == 0:
        boo[k] = True
    if j == 1:
        boo[k] = False
    if j == 2:
        ans.append(boo[k])
    if j == 3:
        f = True
        for l in range(k + 1, n + 1):
            if boo[l]:
                f = False
                break
        if f:
            ans.append("none")
        else:
            ans.append(l)
    if j == 4:
        f = True
        for l in range(k - 1, -1, -1):
            if boo[l]:
                f = False
                break
        if f:
            ans.append("none")
        else:
            ans.append(l)
sys.stdout.close()
sys.stdout = open("out2.txt", "w")
for i in range(len(ans)):
    print(ans[i])
sys.stdout.close()
