class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        mos_list = [".-","-...","-.-.","-..",".","..-.","--.",
                    "....","..",".---","-.-",".-..","--","-.",
                    "---",".--.","--.-",".-.","...","-","..-",
                    "...-",".--","-..-","-.--","--.."]
        mos_dict = {}
        result = set()
        
        for i in range(len(mos_list)):
            mos_dict[chr(ord('a') + i)] = mos_list[i]
            
        for word in words:
            mos_str = ""
            for ch in word:
                mos_str += mos_dict[ch]
            result.add(mos_str)

        return len(result)
