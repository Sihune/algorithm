def solution(N, stages):
    result = {}
    totalPlayer = len(stages)

    for stage in range(1, N+1):
        if totalPlayer != 0:
            count = stages.count(stage)
            result[stage] = count / totalPlayer
            totalPlayer -= count
        else:
            result[stage] = 0
    return sorted(result, key=lambda x: result[x], reverse=True)


print(solution(4, [4,4,4,4,4]))