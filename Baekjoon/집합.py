import sys

M = int(input())
answer = []
bit = 0 

for _ in range(M):
    command = sys.stdin.readline().split()
    if len(command) == 1:
        if command[0] == "all":
            bit = (1 << 20) - 1
        else:
            bit = 0
    else:
        op, num = command[0], int(command[1]) - 1
        if op == "add":
            bit |= 1 << num
        elif op == "check":
            if bit & (1 << num) == 0: 
                print(0)
            else: 
                print(1)
        elif op == "remove":
            bit &= ~(1 << num)
        elif op == "toggle":
            bit ^= (1 << num)
            



