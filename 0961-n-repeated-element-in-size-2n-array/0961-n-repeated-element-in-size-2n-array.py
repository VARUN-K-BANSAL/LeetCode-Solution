class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        max_count = 0
        most_frequent = None
        for key, value in d.items():
            if value > max_count:
                max_count = value
                most_frequent = key
        return most_frequent
