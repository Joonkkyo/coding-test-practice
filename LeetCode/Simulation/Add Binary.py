class Solution:
    def addBinary(self, a: str, b: str) -> str:
        bin_a = list(a)
        bin_b = list(b)
        answer, carry = '', 0
        
        while bin_a or bin_b or carry:
            if bin_a:
                carry += int(bin_a.pop())
                
            if bin_b:
                carry += int(bin_b.pop())
                
            answer += str(carry % 2)
            carry //= 2
                
        return answer[::-1]
