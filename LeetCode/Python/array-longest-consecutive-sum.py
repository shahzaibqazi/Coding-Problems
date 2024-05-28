class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
            
        nums.sort()

        longest_seq = 1
        curr_seq = 1
        for i in range(1, len(nums)):
            if nums[i] == (nums[i-1] + 1):
                curr_seq = curr_seq + 1
                longest_seq = curr_seq if curr_seq > longest_seq else longest_seq
            elif nums[i] != nums[i-1]:
                longest_seq = curr_seq if curr_seq > longest_seq else longest_seq
                curr_seq = 1
        return longest_seq
