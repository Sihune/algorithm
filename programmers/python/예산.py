def solution(d, budget):
    d.sort()

    cnt = 0
    for x in d:
        cnt += 1
        budget -= x
        if budget == 0:
            return cnt
        elif budget < 0:
            return cnt - 1
    return cnt
