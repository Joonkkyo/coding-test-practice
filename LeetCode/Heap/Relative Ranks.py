class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        rank_list = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        heap, rank_dict = [], {}
        answer = []
        
        if len(score) > 3:
            for i in range(4, len(score) + 1):
                rank_list.append(str(i))
        
        for i in range(len(score)):
            heapq.heappush(heap, (-score[i], score[i]))
            
        while heap:
            rank_dict[heapq.heappop(heap)[1]] = rank_list.pop(0)
            
        for i in range(len(score)):
            answer.append(rank_dict[score[i]])
            
        return answer
