class Solution:
    def reverseWords(self, s: str) -> str:
        words=s.split(' ')
        ret=[]
        for word in words:
            ret.append(word[::-1])
        return ' '.join(ret)