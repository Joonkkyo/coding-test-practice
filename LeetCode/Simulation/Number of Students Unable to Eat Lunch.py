class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        move = 0
        
        while students:
            if  students[0] == sandwiches[0]:
                students.pop(0)
                sandwiches.pop(0)
                move = 0
            else:
                students.append(students.pop(0))
                move += 1
                if move == len(students):
                    break
            
        return len(students)
            
