#이분 그래프 판별은 dfs, bfs로 판별이 가능하다
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)

def DFS(v):
   global isVaild
   visited[v] = True
   for i in MAP[v]:
      if not visited[i]:
         group[i] = (group[v]+1) % 2
         print(group)
         DFS(i)
      elif group[v] == group[i]: #이미방문(이미 그룹이 정해짐) 이 코드에선 이제 그룹이 같은지 다른지 판별만 하면 됨
            isVaild = False    

#한 vertex를 기준으로 갈 수 있는 경우의 수가 2개 이상 & index를 기준으로 중간에 있는 vertex의 index를 건너 띄울수 있으면 False

if __name__ == "__main__":
  #print("입력하세요")                     
  T = int(input())
  for _ in range(T):
      isVaild = True
      vertex, edge = map(int, input().split())
      visited = [False] * (vertex+1)
      group = [0] * (vertex+1)
      MAP = [[]for _ in range(vertex+1)]
      for _ in range(edge):
         start, end = map(int, input().split())
         MAP[start].append(end)
         MAP[end].append(start)
      print(MAP)     
      for i in range(1, vertex+1): #모든 노드에 대해 다 살펴봐야 하기 때문에 처음부터 끝까지 반복문(그래프가 끊겼을 수도 있고 & 우리가 궁극적으로 하려는건 이분 그래프를 판별하려는 것이기 때문(각 노드마다 어떤 노드와 연결되어 있는지 일일이 다 확인해야 판별 가능))
            if isVaild:
               DFS(i)
            else:
               break  
      if isVaild:
         print("YES")
      else:
         print("NO")