def solution(absolutes, signs):
    answer = 0
    for num, op in zip(absolutes, signs):
        answer += (num if op else -num)

    return answer

print(solution([4,7,12]	,[True,False,True]))
# print(solution([4,7,12]	,[True,False,True]))