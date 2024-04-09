import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000000)

N = int(input())
tree = [0] * (N+1)
visited = [False] * (N+1)
count = -1
right_cnt = 0

for _ in range(N):
    r, s, e = map(int, input().split())
    tree[r] = [s, e]


def DFS(root):
    global count
    visited[root] = True
    count += 1

    left = tree[root][0]
    right = tree[root][1]

    if left != -1 and not visited[left]:
        visited[left] = True
        DFS(left)
        count += 1  # 되돌아올때 count 함

    if right != -1 and not visited[right]:
        visited[right] = True
        DFS(right)
        count += 1  # 되돌아올때 count 함


def DFS2(root):
    global right_cnt
    visited[root] = True

    right = tree[root][1]

    if right != -1 and not visited[right]:
        visited[right] = True
        DFS2(right)
        right_cnt += 1  # 되돌아올때 count 함


DFS(1)
visited = [False] * (N+1)
DFS2(1)
print(count-right_cnt)
