class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        first_str, sec_str, target_str = '', '', ''
        for ch in firstWord:
            first_str += str(ord(ch) - 97)
        for ch in secondWord:
            sec_str += str(ord(ch) - 97)
        for ch in targetWord:
            target_str += str(ord(ch) - 97)
             
        return True if int(first_str) + int(sec_str) == int(target_str) else False
