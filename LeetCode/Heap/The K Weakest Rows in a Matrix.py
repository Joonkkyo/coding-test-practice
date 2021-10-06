class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        heap, answer = [], []
        row, col = len(mat), len(mat[0])
        
        for i in range(row):
            soldier = sum(mat[i])
            heapq.heappush(heap, (soldier, i))
            
        for _ in range(k):
            answer.append(heapq.heappop(heap)[1])
            
        return answer
            
