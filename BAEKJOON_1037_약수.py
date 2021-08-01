nCnt = int(input())

divisors = list(map(int, input().split(' ')))

maxDivisor = max(divisors)
minDivisor = min(divisors)

print(maxDivisor * minDivisor)