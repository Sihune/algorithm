def to_days(date):
    year, month, day = map(int, date.split("."))
    return year * 28 * 12 + month * 28 + day

def solution(today, terms, privacies):
    # today: 오늘 날짜
    # terms: 유효 기간
    # privacies: 수집된 개인정보
    answer = []

    today = "".join(today.split('.'))
    term_map = {term[0]:int(term[2:]) for term in terms}

    for i, privacy in enumerate(privacies):
        date, term_type = privacy.split(' ')
        year, month, day = [int(x) for x in date.split('.')]
        month = month + term_map[term_type]

        year = year + month // 12 - (0 if month % 12 != 0 else 1)
        month = (month % 12 if month % 12 != 0 else 12)

        dates = year*10000 + month*100 + day
        print(dates, today)
        if int(today) >= dates:
            answer.append(i+1)

    return answer

# 28진수로 날짜를 변환해서 생각...
def solution_other(today, terms, privacies):
    months = {v[0]: int(v[2:]) * 28 for v in terms}
    today = to_days(today)
    expire = [
        i + 1 for i, privacy in enumerate(privacies)
        if to_days(privacy[:-2]) + months[privacy[-1]] <= today
    ]
    return expire



today = "2020.01.01"
terms = ["Z 3", "D 20"]
privacies = ["2019.04.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]

print(solution(today, terms, privacies))
