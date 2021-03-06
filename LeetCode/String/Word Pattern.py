class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s_slice = s.split()
        lookup_1, lookup_2, pattern_arr_1, pattern_arr_2 = {}, {}, [], []
        key = 0
        
        for word in s_slice:
            if word not in lookup_1:
                lookup_1[word] = key
                pattern_arr_1.append(key)
                key += 1
            else:
                pattern_arr_1.append(lookup_1[word])
                
        key = 0
        
        for ch in pattern:
            if ch not in lookup_2:
                lookup_2[ch] = key
                pattern_arr_2.append(key)
                key += 1
            else:
                pattern_arr_2.append(lookup_2[ch])
                
        return True if pattern_arr_1 == pattern_arr_2 else False
