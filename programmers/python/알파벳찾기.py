def solution(s):
    dict = {}
    maxVal = 0
    s = s.lower()
    for c in s:
        if c in dict:
            dict[c] += 1
        else:
            dict[c] = 1
        maxVal = max(maxVal, dict[c])

    upperC = {}
    lowerC = set()
    for c in dict.keys():
        if dict[c] == maxVal:
            if c == 't' or c == 'o' or c == 's':
                upperC[c] = 1
            else:
                lowerC.add(c)

    answer = ''
    if 't' in upperC:
        answer += 'T'
    if 'o' in upperC:
        answer += 'O'
    if 's' in upperC:
        answer += 'SS'

    return answer + ''.join(sorted(lowerC))

print(solution("aaBBTtooSS"))