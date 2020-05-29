class Solution:
    def canCross(self, stones: List[int]) -> bool:
        dp={i:set() for i in stones}
        i=stones.pop(0)
        if i+1 in dp:
            dp[i+1].add(1)
        del dp[0]
        for i,ks in dp.items():
            for k in ks:
                if k>1 and i+k-1 in dp:
                    dp[i+k-1].add(k-1)
                if k>0 and i+k in dp:
                    dp[i+k].add(k)
                if i+k+1 in dp:
                    dp[i+k+1].add(k+1)
        if dp[stones[-1]]:
            return True
        return False