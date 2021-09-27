class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        answer = []
        for i in range(len(code)):
            sum, idx = 0, 0
            if k > 0:
                for j in range(k):
                    idx = (i + j + 1) % len(code)
                    sum += code[idx]

                answer.append(sum)
            elif k < 0:
                for j in range(-k):
                    if i - j - 1 < 0: idx = i - j - 1 + len(code)
                    else: idx = i - j - 1
                    sum += code[idx]
                answer.append(sum)
            else:
                answer.append(0)
        return answer
                
