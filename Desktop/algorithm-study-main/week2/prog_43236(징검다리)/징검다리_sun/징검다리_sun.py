## 아직 다 푼거 아님!

def check_weight(rocks, weight, n):
    impossible = 0
    for i in range(1, len(rocks)):
        if rocks[i] - rocks[i-1] > weight:  # 만일 주어진 용량으로 못 건널 때
            impossible += 1

    if impossible <= n:  # 만일 n개를 제외하고 wieght 간격으로 건너기 가능
        return True
    else:  # 건너기
        return False


def solution(distance, rocks, n):
    answer = 0
    rocks = [0] + rocks + [distance]
    rocks.sort()

    low = 0
    high = distance

    while low <= high:
        mid = (low + high) // 2
        flag = check_weight(rocks, mid, n)
        # print(f"rocks {rocks} mid {mid} flag {flag}")

        if flag:  # 만일 지나갈 수 있을 때
            high = mid - 1

        else:  # 만일 못 지나감
            low = mid + 1

    answer = low
    return answer
