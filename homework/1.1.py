a = int(input())
b = [int(n) for n in input().split()]
c = b[0]
IRR = 1
for i in range(1, a + 1):
    c = c + b[i] / ((1 + IRR) ** i)
print (c)
