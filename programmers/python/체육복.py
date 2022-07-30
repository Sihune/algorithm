def solution(n, lost, reserve):
    operation = [-1, 1, 0]
    n_lost = set(lost) - set(reserve)
    n_reserve = set(reserve) - set(lost)
    n -= len(n_lost)

    for x in n_lost:
        for op in operation:
            if x+op in n_reserve:
                n += 1
                n_reserve.remove(x+op)
                break
    return n
