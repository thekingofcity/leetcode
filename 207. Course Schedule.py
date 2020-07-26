class Solution:
    def canFinish(self, numCourses: int,
                  prerequisites: List[List[int]]) -> bool:
        prerequisite = {}
        for a, b in prerequisites:
            prerequisite.setdefault(a, []).append(b)

        c = [i not in prerequisite for i in range(numCourses)]

        flag = True
        while flag:
            flag = False
            used_k = []  # do not modify dict on fly
            for k, v in prerequisite.items():
                if all([c[each] for each in v]):
                    c[k] = True
                    flag = True
                    used_k.append(k)
            for k in used_k:
                del prerequisite[k]

        return all(c)
