import sys

def check_dis(distance, homes):
    stand = homes[0]
    cnt = 1
    for i in range(1, len(homes)):
        if homes[i] - stand >= distance: # 거리가 충분히 먼 경우 -> 공유기 설치
            stand = homes[i]
            cnt += 1

        if cnt >= C: # 만일 distance를 더 줄여야하는 경우 
            return True
    
    return False  # 만일 distance를 더 늘려야하는 경우

if __name__ == "__main__":
    input = sys.stdin.readline

    N, C = map(int, input().split())
    homes = []
    for _ in range(N):
        new = int(input())
        homes.append(new)

    homes.sort()
    low = 0
    high = 1000000000
    answer = 0
    while low <= high:
        mid = (low + high) // 2
        flag = check_dis(mid, homes)
        if flag:
            low = mid + 1
            answer = max(answer, mid)
        else:
            high = mid - 1

    print(answer)