class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        lookup = {}
        s_arr, t_arr = [], []
        key = 0
        for ch in s:
            if ch not in lookup:
                lookup[ch] = key
                s_arr.append(key)
                key += 1
            else:
                s_arr.append(lookup[ch])

        lookup = {}
        key = 0
        for ch in t:
            if ch not in lookup:
                lookup[ch] = key
                t_arr.append(key)
                key += 1
            else:
                t_arr.append(lookup[ch])

        return True if s_arr == t_arr else False
