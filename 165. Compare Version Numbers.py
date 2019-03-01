class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1=version1.split('.')
        v2=version2.split('.')
        l=abs(len(v1)-len(v2))
        fill=[0 for i in range(l)]
        if len(v1)-len(v2)>0:
            v2.extend(fill)
        else:
            v1.extend(fill)
        for i in range(len(v1)):
            if int(v1[i])>int(v2[i]):
                return 1
            elif int(v1[i])<int(v2[i]):
                return -1
            else:
                pass
        return 0