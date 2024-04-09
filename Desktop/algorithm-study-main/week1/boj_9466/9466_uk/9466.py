import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)

def dfs(v):
  global team
  visited[v] = True
  cycle.append(v)
  next_idx = MAP[v]
  if visited[next_idx]: #사이클 판별(이미 방문했던걸 또 접근했기 때문)
    if next_idx in cycle:
       team += cycle[cycle.index(next_idx):]   #사이클을 처음 시작하는 애부터 들어가야됨, 중복 index일 경우 맨 처음부터 알려주니까
    return    
  else:  #사이클 그리기
      dfs(next_idx)
    
     
if __name__ == "__main__":
  #print("입력하세요")                     
  T = int(input())
  for _ in range(T):
    N = int(input())
    MAP = [0] + list(map(int, input().split()))
    visited = [False] * (N+1)   
    team = []
    for j in range(1 , N+1):
        if not visited[j]:
           cycle = []
           dfs(j)
    print(N - len(team))