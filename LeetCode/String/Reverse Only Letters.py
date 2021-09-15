class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        start, end = 0, len(s) - 1
        str_list = list(s)
        
        while start < end:
            if not str_list[start].isalpha():
                start += 1
            elif not str_list[end].isalpha():
                end -= 1
            else:
                str_list[start], str_list[end] = str_list[end], str_list[start]
                start += 1
                end -= 1
                
        return "".join(str_list)
