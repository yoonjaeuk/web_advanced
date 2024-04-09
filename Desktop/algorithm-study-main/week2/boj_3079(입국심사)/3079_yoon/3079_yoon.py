import sys
input = sys.stdin.readline

N, M = map(int, input().split())
time = []    # 각 심사대에서 심사를 받는데 걸리는 시간 

for i in range(N):
    K = int(input())
    time.append(K)
    
l = min(time)
answer = r = max(time) * M 

while l <= r:
    total = 0   # mid시간 동안 검사할 수 있는 총 사람의 수
    
    m = (l+r) // 2
    
    for i in range(N):
        total += m // time[i] # 각 작업별로 m시간동안 몇 번 수행 가능한 지 계산
        
    if total >= M:  # 목표 작업 수 이상인 경우 범위 축소
        r = m - 1 
        answer = min(answer, m)
        
    else:   # 범위를 늘려 탐색 
        l = m + 1
        
print(answer)