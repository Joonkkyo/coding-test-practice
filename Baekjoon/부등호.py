def check(num1, num2, symbol):
    if num1 > num2 and symbol == '>':
        return True
    elif num1 < num2 and symbol == '<':
        return True
    
    return False

def dfs(depth, s):
    global min_ans, max_ans
    if depth == k + 1:
        if len(min_ans) == 0:
            min_ans = s
        else:
            max_ans = s
        
        return
    
    for i in range(10):
        if not visited[i]:
            if depth == 0 or check(s[-1], str(i), symbol_list[depth - 1]):
                visited[i] = True
                dfs(depth + 1, s + str(i))
                visited[i] = False
                
                
k = int(input())
symbol_list = list(input().split())
visited = [False] * 10
min_ans, max_ans = "", ""
        
dfs(0, "")
print(max_ans)
print(min_ans)
