class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        keyDict, answer = {}, []
        idx = 0
        str_list = ["qwertyuiop","asdfghjkl", "zxcvbnm"]
        
        for i in range(len(str_list)):
            for j in range(len(str_list[i])):
                keyDict[str_list[i][j]] = i
        
        for word in words:
            flag = True
            word = word.lower()
            criterion = keyDict[word[0]]
            
            for i in range(1, len(word)):
                if criterion != keyDict[word[i]]:
                    flag = False
                    break
           
            if flag: answer.append(words[idx])
            idx += 1
            
        return answer
                
