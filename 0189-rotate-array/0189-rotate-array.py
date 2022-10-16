class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n= len(nums)
        k%=n
        if n<2 or k==9:
            return
        nums[:]= nums[::-1]
        nums[:k]= nums[:k][::-1]
        nums[k:]= nums[k:][::-1]

        