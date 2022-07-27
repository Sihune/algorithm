def solution(new_id):
    answer =''
    new_id = new_id.lower()
    for c in new_id:
        if c.isdigit() or c.isalpha() or c in ['_','-','.']:
            answer += c

    while '..' in answer:
        answer = answer.replace('..', '.')

    if answer[0] == '.':
        answer = answer[1:] if len(answer) > 1 else '.'
    if answer[-1] == '.':
        answer = answer[:-1]

    if len(answer) == 0:
        answer = 'a'
    answer = answer[0:15]
    if answer[-1] == '.':
        answer = answer[:-1]

    while len(answer) < 3:
        answer += answer[-1]

    return answer

print(solution("z-+.^."))