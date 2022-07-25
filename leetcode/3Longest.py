class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret = 1 if len(s) >= 1 else 0
        for i in range(0, len(s)):
            alphMap = {}
            flag = 0
            for j in range(i, len(s)):
                if s[j] in alphMap:
                    ret = max(ret, j - i)
                    flag = 1
                    break
                alphMap[s[j]] = 1
            if flag == 0:
                ret = max(ret, len(s) - i)
        return ret


print(Solution().lengthOfLongestSubstring("au"))
