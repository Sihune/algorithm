import math

def is_prime_number(x):
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False 
    return True 

def dfs(nums, num, k, s):
    if k == 3:
        if is_prime_number(num):
            return 1
        return 0
    
    for x in range(s, len(nums)):
        return dfs(nums, num+nums[x], k+1, x+1) + dfs(nums, num, k, x+1)
    
    return 0

def my_solution(nums):
    return dfs(nums, 0, 0, 0)


def solution(nums):
    from itertools import combinations as cb
    answer = 0
    for a in cb(nums, 3):
        cand = sum(a)
        for j in range(2, cand):
            if cand%j==0:
                break
        else:
            answer += 1
    return answer


print(solution([1,2,3,4]))
print(solution([1,2,7,6,4]))