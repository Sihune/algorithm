import heapq

def solution(scoville, K):
    heap = []

    for sc in scoville:
        heapq.heappush(heap, sc)

    cnt = 0
    while len(heap) > 0:
        first = heapq.heappop(heap) if len(heap) >= 1 else -1
        second = heapq.heappop(heap) if len(heap) >= 1 else -1

        if first >= K:
            break
        elif second == -1:
            return -1

        cnt += 1

        heapq.heappush(heap, first + second * 2)

    return cnt


print(solution([1, 1], 7))