import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

def dfs(sNum):
    global ans
    visited[sNum] = 1   # 방문 체크 
    c.append(sNum)
    nNum = arr[sNum]
    if visited[nNum]:
        if nNum in c:
            ans += c[c.index(nNum):]
        return 
    else:
        dfs(nNum)    # 더 깊이 파고든다. 


T = int(input())

for _ in range(T):
    n = int(input())
    arr = [0] + list(map(int, input().split()))
    visited = [0 for _ in range(n+1)]
    ans = []
    for i in range(1, n+1):
        if visited[i] == False:
            c = []  # 하나의 사이클 안의 원소를 담음 
            dfs(i)
            
    print(n-len(ans))
