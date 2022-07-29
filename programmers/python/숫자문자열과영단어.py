digit = {'zero': '0', 'one': '1', 'two': '2', 'three': '3', 'four': '4', 'five': '5', 'six': '6', 'seven': '7',
         'eight': '8', 'nine': '9'}


def my_solution(s):
    answer = ''

    num = ''
    for c in s:
        if not c.isdigit():
            num += c
        else:
            answer += c

        if num in digit:
            answer += digit[num]
            num = ''

    return int(answer)


def solution(s):
    answer = s
    for key, val in digit.items():
        answer = answer.replace(key, val)
    return int(answer)


print(solution("23four5six7"))
