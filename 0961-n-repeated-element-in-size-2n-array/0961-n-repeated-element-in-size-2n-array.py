class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            if i in d:
                d[i] +=1
            else:
                d[i] = 1
        max = 0
        ans = None
        for key,values in d.items():
            if max < values:
                max = values
                ans = key
        return ans