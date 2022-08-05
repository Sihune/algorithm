
def solution(s):

    bf = len(s)
    af = 0
    while bf != af:
        # print(s)
        que = []
        bf = len(s)
        for c in s:
            if len(que) == 0:
                que.append(c)
                continue
            cur = que.pop()
            if cur != c:
                que.append(cur)
                que.append(c)
        s = ''.join(que)
        af = len(s)

    return 1 if len(s) == 0 else 0


print(solution("baabaa"))
print(solution("cdcd"))