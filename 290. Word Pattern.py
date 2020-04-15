class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        p2w={}
        w2p=set()
        words=str.split(' ')
        if len(pattern)!=len(words): return False
        for c in pattern:
            if c in p2w:
                if p2w[c]!=words.pop(0):
                    return False
            else:
                _=words.pop(0)
                if _ in w2p:
                    return False
                p2w[c]=_
                w2p.add(_)
        return True
