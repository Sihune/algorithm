import math

def solution(progresses, speeds):
    answer = []
    works = [math.ceil((100 - progress) / speed) for progress, speed in zip(progresses, speeds)] + [101]

    cnt = 1
    cur = works[0]
    for i in range(1, len(works)):
        if cur < works[i]:
            answer.append(cnt)
            cur = works[i]
            cnt = 1
        else:
            cnt += 1

    return answer

print(solution([93, 30, 55], [1, 30, 5]))
print(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]))