class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        dic, temp_list = {}, []
        
        for i in range(len(order)):
            dic[order[i]] = chr(ord('a') + i)
        
        for word in words:
            temp_str = ''
            for i in range(len(word)):
                temp_str += dic[word[i]]
            temp_list.append(temp_str)
            
        new_list = sorted(temp_list)
        
        return True if new_list == temp_list else False
