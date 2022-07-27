def solution(lottos, win_nums):
    cnt = 0
    zero = 0
    for num in lottos:
        if num == 0:
            zero += 1
        if num in win_nums:
            cnt += 1

    return [6 if 7 - zero - cnt > 6 else 7 - zero - cnt , 6 if 7 - cnt > 6 else 7 - cnt]


print(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]))

print(solution([0, 0, 0, 0, 0, 0], [38, 19, 20, 40, 15, 25]))

print(solution([1,2,5,6,7,8], [20, 9, 3, 45, 4, 35]))
