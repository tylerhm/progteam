def bfs(adjList, skipU, skipV, n):
    q = []
    visited = [False for _ in range(n)]
    q.append(0)
    visited[0] = True
    while q:
        u = q.pop(0)
        for v in adjList[u]:
            if visited[v]:
                continue
            if u == skipU and v == skipV:
                continue
            q.append(v)
            visited[v] = True
    return visited[n-1]

def solve():
    n, m = [int(x) for x in input().split()]
    adjList = [[] for _ in range(n)]
    for _ in range(m):
        u, v = [int(x) for x in input().split()]
        u-=1
        v-=1
        adjList[u].append(v)
        adjList[v].append(u)
    for u in range(n):
        for v in adjList[u]:
            skipU, skipV = u, v
            if not bfs(adjList, skipU, skipV, n):
                print("Halt, Spiderman! Plans Thwarted!")
                return
    print("How Sad, Perpetrator Triumphed")


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()