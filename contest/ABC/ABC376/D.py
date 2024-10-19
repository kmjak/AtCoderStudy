from collections import deque

N, M = map(int, input().split())
g = [list() for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    g[a - 1].append(b - 1)

inf = 10**9
d = [inf] * N
Q = deque()

d[0] = 0
Q.append(0)

while len(Q) > 0:
    cur = Q.popleft()
    for dst in g[cur]:
        if dst == 0:
            print(d[cur] + 1)
            exit()
        if d[dst] == inf:
            d[dst] = d[cur] + 1
            Q.append(dst)

print(-1)
