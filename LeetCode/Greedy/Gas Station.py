class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        gas_len = len(gas)
        answer, fuel = 0, 0
        
        if sum(gas) < sum(cost):
            return -1
        
        for i in range(gas_len):
            fuel += gas[i] - cost[i]
            
            if fuel < 0:
                answer = i + 1
                fuel = 0
                continue
                
        return answer

