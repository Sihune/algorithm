from math import sqrt, trunc

def solution(left, right):
    return sum([-x if sqrt(x) - trunc(sqrt(x)) == 0 else x for x in range(left, right+1)])


print(solution(24,27))