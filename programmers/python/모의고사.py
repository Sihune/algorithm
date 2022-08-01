from math import ceil


def solution(answers):
    ret = []

    noMath = [[1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]

    first = 0
    for i in range(0, 3):
        cnt = 0
        cur = noMath[i] * ceil(len(answers) / len(noMath[i]))
        for idx, answer in enumerate(answers):
            if answer == cur[idx]:
                cnt += 1
        first = max(cnt, first)
        ret.append(cnt)

    # ret = ret.index(first) + 1
    # print(ret)
    ret = [-1] + ret

    return list(filter(lambda x: ret[x] == first, range(len(ret))))


print(solution([1, 2, 3, 4, 5, 1,2,3,4,5,1,2,3,4,5,1,2]))
print(solution([1, 3, 2, 4, 2]))
