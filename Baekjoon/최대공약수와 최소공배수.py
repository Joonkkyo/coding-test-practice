def GCD(num1, num2):  ## 최대 공약수
    gcd = 1
    for i in range(1, min(num1, num2) + 1):
        if num1 % i == 0 and num2 % i == 0:
            gcd = i
            
    return gcd
   
        
def LCM(num1, num2): ## 최소공배수
    gcd = GCD(num1, num2)
    share1, share2 = num1 // gcd, num2 // gcd
    lcm = share1 * share2 * gcd
    return lcm

A, B = map(int, input().split())
print(GCD(A, B))
print(LCM(A, B))
