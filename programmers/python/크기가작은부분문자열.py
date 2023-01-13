def solution(t, p):
    answer = 0
    plen = len(p)
    for i in range(0, len(t) - plen+1):
        if int(t[i:i+plen]) <= int(p):
            answer += 1

    return answer


t = "10203"
p = "15"

print(solution(t, p))