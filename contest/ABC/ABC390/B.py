N = int(input())
A = list(map(int, input().split()))

sec = A[1]
fir = A[0]

for i in range(N - 1):
  if A[i] * sec != A[i + 1] * fir:
    print("No")
    exit()

print("Yes")