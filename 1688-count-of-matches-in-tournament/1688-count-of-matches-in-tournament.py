class Solution:
    def numberOfMatches(self, n: int) -> int:
        cnt = 0
        while n>1:
            cnt += n//2
            n = (n+1)//2
        return cnt