class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s_len, t_len = len(s), len(t)
        idx = 0
        
        for i in range(len(t)):
            if idx < s_len and t[i] == s[idx]:
                idx += 1
            else:
                continue
        
        return True if idx == s_len else False
