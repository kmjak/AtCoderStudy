N,K = map(int, input().split())
A = list(map(int, input().split()))

P = 1
for _ in range(K):
  P*=10

res = 1

for x in A:
  res *= x
  if res >= P:
    res = 1
print(res)