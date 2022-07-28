def solution(records):
    answer = []

    user = {}
    for record in records:
        rec = record.split(' ')
        if rec[0] != 'Leave':
            user[rec[1]] = rec[2]

    for record in records:
        rec = record.split(' ')
        if rec[0] == 'Enter':
            answer.append(user[rec[1]] + "님이 들어왔습니다.")
        elif rec[0] == 'Leave':
            answer.append(user[rec[1]] + "님이 나갔습니다.")

    return answer


print(solution(["Enter uid1234 Muzi",
                "Enter uid4567 Prodo",
                "Leave uid1234",
                "Enter uid1234 Prodo",
                "Change uid4567 Ryan"]))
