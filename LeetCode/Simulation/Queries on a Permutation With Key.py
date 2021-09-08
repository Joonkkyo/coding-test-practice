class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        num_list = [i + 1 for i in range(m)]
        answer = []
        
        for i in range(len(queries)):
            answer.append(num_list.index(queries[i]))
            num_list.remove(queries[i])
            num_list.insert(0, queries[i])
            
        return answer
          
                          
            
