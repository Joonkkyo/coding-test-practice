class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g_len, s_len = len(g), len(s)
        idx, answer = 0, 0
        g.sort()
        s.sort()

        for i in range(s_len):
            if idx > g_len - 1:
                return answer
            if g[idx] <= s[i]:
                answer += 1
                idx += 1
            else:
                continue
        
        return answer
