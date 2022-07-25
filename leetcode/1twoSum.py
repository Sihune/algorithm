

class Solution(object):
    def twoSum_mycode(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        num_dict = {}
        for i, x in enumerate(nums):
            num_dict[x] = []

        for i, x in enumerate(nums):
            num_dict[x].append(i)
            if len(num_dict[x]) == 2 and x*2 == target:
                return num_dict[x]

        for i, x in enumerate(nums):
            find_num = target - x

            if find_num not in num_dict:
                continue

            if len(num_dict[find_num]) == 1 and i != num_dict[find_num][0]:
                return sorted([i, num_dict[find_num][0]])

    def twoSum(self, nums, target):
        hashMap = {}
        for i, x in enumerate(nums):
            component = target - x
            if component in hashMap:
                return [hashMap[component],i]
            hashMap[x] = i
        
s = Solution()

print(s.twoSum([-1,-2,-3,-4,-5], -8))