class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        criterion = Counter(chars)
        answer = 0
        
        for word in words:
            flag = True
            word_count = Counter(word)
            if len(word_count) > len(criterion):
                continue
                
            for i in range(len(word)):
                if word_count[word[i]] > criterion[word[i]]:
                    flag = False
                    break

            if flag: answer += len(word)

        return answer
