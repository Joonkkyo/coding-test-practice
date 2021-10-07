class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = [False for _ in range(len(rooms))]

        def dfs(rooms, idx):
            if visited[idx]:
                return
            
            visited[idx] = True 
            for i in rooms[idx]:
                dfs(rooms, i)
            
        dfs(rooms, 0)
        return all(visited)
