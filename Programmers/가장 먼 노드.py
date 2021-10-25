from collections import deque

def solution(n, edge):
    graph = [[] for _ in range(n + 1)]
    answer = 0
    depth = 0
    queue = deque([[1, 0]])
    depth_list = [-1] * (n + 1)
    
    for i in range(len(edge)):
        graph[edge[i][0]].append(edge[i][1])
        graph[edge[i][1]].append(edge[i][0])

    while queue:
        idx, depth = queue.popleft()
        depth_list[idx] = depth
        
        for node in graph[idx]:
            if depth_list[node] == -1:
                queue.append([node, depth + 1])
                depth_list[node] = 0
                
    answer = depth_list.count(max(depth_list))     
    return answer
