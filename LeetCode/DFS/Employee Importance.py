"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        graph = {employee.id: employee for employee in employees}
        
        def dfs(i):
            employee = graph[i]
            return employee.importance + sum(dfs(j) for j in employee.subordinates)
        
        return dfs(id)
