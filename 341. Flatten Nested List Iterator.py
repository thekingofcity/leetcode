# https://leetcode.com/problems/flatten-nested-list-iterator/discuss/80146/Real-iterator-in-Python-Java-C%2B%2B
# iterator: prepare the elem in hasNext and get in next

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """


class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.s = [[nestedList, 0], ]

    def next(self) -> int:
        nestedList, i = self.s[-1]
        self.s[-1][1] += 1
        return nestedList[i].getInteger()

    def hasNext(self) -> bool:
        while self.s:
            nestedList, i = self.s[-1]
            if i == len(nestedList):
                self.s.pop()
            else:
                if nestedList[i].isInteger():
                    return True
                self.s[-1][1] += 1
                self.s.append([nestedList[i].getList(), 0])
        return False

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())