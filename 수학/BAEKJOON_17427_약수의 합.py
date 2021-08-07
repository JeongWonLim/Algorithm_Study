import sys

sumN = [int(0) for i in range(1000001)]
for i in range(1, 1000001):
    j = 1
    while i * j < 1000001:
        sumN[j*i] += i
        j += 1
    sumN[i] += sumN[i - 1]

T = int(sys.stdin.readline())

for Tc in range(T):
    N = int(sys.stdin.readline())
    sys.stdout.write("{}\n".format(sumN[N]))