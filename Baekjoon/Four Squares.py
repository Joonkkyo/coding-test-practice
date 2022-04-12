N = int(input())

def solve(n):
    if n ** 0.5 == int(n ** 0.5):
        return 1 
    
    for i in range(1, int(n ** 0.5) + 1):
        if (n - i ** 2) ** 0.5 == int((n - i ** 2) ** 0.5):
            return 2
        
    for i in range(1, int(n ** 0.5) + 1):
        for j in range(1, int((n - i ** 2) ** 0.5) + 1):
            if (n - i ** 2 - j ** 2) ** 0.5 == int((n - i ** 2 - j ** 2) ** 0.5):
                return 3
            
    return 4

print(solve(N))
