import sys

T = int(input())
for _ in range(T):
    board, n = [], int(sys.stdin.readline())
    dp = [[0] * n for _ in range(2)]

    for _ in range(2):
        board.append(list(map(int, sys.stdin.readline().split())))
        
    if n != 1:
        dp[0][0] = board[0][0]
        dp[1][0] = board[1][0]
        dp[0][1] = board[1][0] + board[0][1]
        dp[1][1] = board[0][0] + board[1][1]
        for i in range(2, n):
            dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + board[0][i]
            dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + board[1][i]
        print(max(dp[0][n - 1], dp[1][n - 1]))    
    else:
        print(max(board[0][0], board[1][0]))
        
        
    

    
