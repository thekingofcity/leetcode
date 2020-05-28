class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        a,b = equations.pop(0)
        vs=[{b:1.0,a:values.pop(0)}]
        equations_next=[]
        values_next=[]
        last=0
        while equations or equations_next:
            if not equations:
                last=len(equations_next)
                equations, equations_next = equations_next, equations
                values, values_next = values_next, values
            a,b=equations.pop(0)
            val=values.pop(0)
            flag=False
            for v in vs:
                if a in v:
                    v[b]=v[a]/val
                    flag=True
                    break
                elif b in v:
                    v[a]=v[b]*val
                    flag=True
                    break
            if not flag:
                if last==len(equations_next)+1:
                    vs.append({b:1.0,a:val})
                else:
                    equations_next.append([a,b])
                    values_next.append(val)
        # print(vs)
        ret=[]
        for query in queries:
            a,b=query
            flag=False
            for v in vs:
                if a in v and b in v:
                    ret.append(v[a]/v[b])
                    flag=True
                    break
            if not flag:
                ret.append(-1.0)
        return ret

# [["x1","x2"],["x2","x3"],["x3","x4"],["x4","x5"]]
# [3.0,4.0,5.0,6.0]
# [["x1","x5"],["x5","x2"],["x2","x4"],["x2","x2"],["x2","x9"],["x9","x9"]]
# [["x","z"],["b","c"],["a","b"]]
# [5.0,3.0,2.0]
# [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"],["x","y"]]
# [["x","z"],["b","c"],["a","b"],["z","a"]]
# [5.0,3.0,2.0,4.0]
# [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"],["x","y"]]
# [["a","b"],["e","f"],["b","e"]]
# [3.4,1.4,2.3]
# [["b","a"],["a","f"],["f","f"],["e","e"],["c","c"],["a","c"],["f","e"]]
# [["a","b"],["b","d"],["e","f"],["b","e"]]
# [3.4,2.0,1.4,2.3]
# [["b","a"],["a","f"],["f","f"],["e","e"],["c","c"],["a","c"],["f","e"]]