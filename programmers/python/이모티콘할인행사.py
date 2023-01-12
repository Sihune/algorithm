
def dfs(discounts, users, emotions):
    global answer
    if len(discounts) == len(emotions):
        # print(discounts)
        discount_emotions = []
        plus_user = 0
        payment = 0
        for i in range(len(discounts)):
            discount_emotions.append(int(emotions[i] * (100 - discounts[i])/100))
        for user_discount, emoji_plus in users:
            pay = 0
            for i in range(len(discounts)):
                if discounts[i] >= user_discount:
                    pay += discount_emotions[i]
            if pay >= emoji_plus: plus_user += 1
            else: payment += pay

        # print(plus_user, payment)
        if plus_user > answer[0]:
            answer = [plus_user, payment]
        elif plus_user == answer[0]:
            answer = [plus_user, payment] if payment > answer[1] else answer
        return

    for i in [10, 20, 30, 40]:
        discounts.append(i)
        dfs(discounts, users, emotions)
        discounts.pop()

def solution(users, emoticons):
    global answer
    answer = [0, 0]
    dfs([], users, emoticons)
    return answer

users = [[40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900]]
emotions = [1300, 1500, 1600, 4900]

print(solution(users, emotions))
