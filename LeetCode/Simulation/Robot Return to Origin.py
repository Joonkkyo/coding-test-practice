class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x, y = 0, 0
        
        for move in moves:
            if move == "R":
                x += 1
            elif move == "L":
                x -= 1
            elif move == "U":
                y += 1
            else:
                y -= 1
                
        return True if x == 0 and y == 0 else False
