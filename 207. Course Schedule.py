class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        prerequisite = {}
        for a,b in prerequisites:
            prerequisite.setdefault(a, []).append(b)

        c=[not i in prerequisite for i in range(numCourses)]

        flag=True
        while flag:
            flag=False
            used_k=list()
            for k,v in prerequisite.items():
                all_=all([c[each] for each in v])
                if all_:
                    c[k]=True
                    flag=True
                    used_k.append(k)
            for k in used_k:
                del prerequisite[k]
                
        return all(c)
