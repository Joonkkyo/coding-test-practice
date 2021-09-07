class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        usage, iteration = 0, 0
        
        while True:
            iteration += 1
            usage += 1
            
            if memory1 >= memory2:
                memory1 -= usage
                if memory1 < 0:
                    return [iteration, memory1 + usage, memory2]
                            
            else:
                memory2 -= usage
                if memory2 < 0:
                    return [iteration, memory1, memory2 + usage]
