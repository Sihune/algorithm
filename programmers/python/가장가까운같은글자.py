def solution(s):
    answer = []

    str_dict = {}
    for x in range(97, 97+27):
        str_dict[chr(x)] = -1

    for i, c in enumerate(s):
        answer.append(-1 if str_dict[c] == -1 else i - str_dict[c])
        str_dict[c] = i

    return answer

print(solution("foobar"))