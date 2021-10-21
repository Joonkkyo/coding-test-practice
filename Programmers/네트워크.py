def solution(n, computers):
    answer = 0
    queue = []
    visited = [False] * n
    
    def bfs(start):
        queue.append(start)
        visited[start] = True
        
        while queue:
            v = queue.pop(0)
            for i in range(n):
                if computers[v][i] == 1 and not visited[i]:
                    queue.append(i)
                    visited[i] = True
        
    for i in range(n):
        if not visited[i]:
            bfs(i)
            answer += 1
            
    return answer


### dfs
# def solution(n, computers):
#     answer = 0
#     visited = [False] * n
    
#     def dfs(start):
#         visited[start] = True
#         for i in range(n):
#             if computers[start][i] == 1 and not visited[i]:
#                 dfs(i)
            
#     for i in range(n):
#         if not visited[i]:
#             dfs(i)
#             answer += 1
            
#     return answer
