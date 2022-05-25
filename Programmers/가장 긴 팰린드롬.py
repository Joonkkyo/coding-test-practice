def isPalindrome(s):
    if s == s[::-1]:
        return True
    
    return False

def solution(s):
    answer = 0
    n = len(s)
    
    for i in range(n):
        for j in range(i + 1, n + 1):
            if isPalindrome(s[i:j]):
                if answer < j - i :
                    answer = j - i
                        
    return answer
