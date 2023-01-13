def solution(storey):
    answer = 0
    storey = [0] + list(map(int, list(str((storey)))))
    for i in range(len(storey)-1, 0, -1):
        if storey[i] > 5:
            answer += 10 - storey[i]
            storey[i-1] += 1
        elif storey[i] == 5:
            answer += 10 - storey[i]
            storey[i-1] += 1 if storey[i-1] >= 5 else 0
        else:
            answer += storey[i]
    return answer + storey[0]

print(solution(55))