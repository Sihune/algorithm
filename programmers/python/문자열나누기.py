def solution(s):
    answer = 0
    pre = post = 0
    pre_char = s[0]
    for c in s:
        if pre == 0 and post == 0: pre_char = c

        if c == pre_char:
            pre += 1
        else:
            post += 1

        if pre == post:
            answer += 1
            pre = post = 0

    return answer + (1 if post != pre else 0)

print(solution("banana"))