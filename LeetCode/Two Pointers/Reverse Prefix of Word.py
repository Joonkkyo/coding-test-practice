class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        word_list = list(word)
        start, end = 0, word.index(ch) if ch in word_list else 0
            
        while start < end:
            word_list[start], word_list[end] = word_list[end], word_list[start]
            start += 1
            end -= 1
            
        return "".join(word_list)
