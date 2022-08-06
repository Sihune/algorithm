
def solution(s):
    answer = ''
    dict = {}

    for c in s:
        if c in dict:
            dict[c] += 1
        else:
            dict[c] = 1

    sorted_dict = sorted(dict.items(), key=lambda item: item[0])

    print(sorted_dict)

    for c, n in sorted_dict:
        print(c)
        for i in range(n):
            answer += c

    return answer


print(solution("Zbcdefg"))