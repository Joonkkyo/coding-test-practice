import sys

while True:
    isPalindrome = True
    num = sys.stdin.readline().strip()
    if num == '0':
        break
    
    for i in range(len(num) // 2):
        if num[i] == num[len(num) - 1 - i]:
            continue
        else:
            isPalindrome = False
            break
        
    if isPalindrome: print('yes') 
    else: print('no')    
