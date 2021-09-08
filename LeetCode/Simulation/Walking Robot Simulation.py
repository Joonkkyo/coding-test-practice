class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obstacles = set((x, y) for x, y in obstacles)
        dx = [0, -1, 0, 1] # 북 서 남 동
        dy = [1, 0, -1, 0]
        
        direction = 0
        max_distance = 0
        x, y = 0, 0
        
        for c in commands:
            if c == -2: # turn left
                direction = (direction + 1) % 4
                
            elif c == -1: # turn right
                direction = (direction - 1) % 4
                
            else:
                for _ in range(c):
                    next_x = x + dx[direction]
                    next_y = y + dy[direction]

                    if (next_x, next_y) in obstacles:
                        break
                    
                    x = next_x
                    y = next_y
            max_distance = max(max_distance, x*x + y*y)
        
        return max_distance
