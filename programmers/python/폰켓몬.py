def solution(nums):
    return len(nums) // 2 if len(set(nums)) > len(nums) // 2 else len(set(nums))

print(solution([3,1,2,3]))
print(solution([3,3,3,2,2,4]))
print(solution([3,3,3,2,2,2]))