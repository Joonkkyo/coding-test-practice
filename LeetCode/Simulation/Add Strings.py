class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        num1 = list(num1)
        num2 = list(num2)
        answer, carry = '', 0
        
        while num1 or num2 or carry:
            if num1:
                carry += int(num1.pop())
            if num2:
                carry += int(num2.pop())
            
            answer += str(carry % 10)
            carry //= 10
            
        return answer[::-1]
            
