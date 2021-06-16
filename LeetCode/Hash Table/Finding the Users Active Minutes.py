class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        answer = [0] * k
        UAM_map = collections.defaultdict(set)

        for ID, time in logs:
            UAM_map[ID].add(time)
            
        for UAM in UAM_map.values():
            answer[len(UAM) - 1] += 1
            
        return answer
