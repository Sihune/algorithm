def solution(cap, n, deliveries, pickups):
    answer = 0
    give = 0
    get = 0
    for i in range(n,0,-1):
        idx = i-1
        if deliveries[idx] != 0 or pickups[idx] != 0:
            cnt = 0
            while give < deliveries[idx] or get < pickups[idx]:
                cnt += 1
                give += cap
                get += cap
            give -= deliveries[idx]
            get -= pickups[idx]
            answer += (i*cnt*2)
    return answer

cap = 2
n = 7
deliveries = [1, 0, 2, 0, 1, 0, 2]
pickups = [0, 2, 0, 1, 0, 2, 0]

print(solution(cap, n, deliveries, pickups))