class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        answer = 0
        lookup = {"type" : 0, "color" : 1, "name" : 2}
        
        for i in range(len(items)):
            if items[i][lookup[ruleKey]] == ruleValue:
                answer += 1
        return answer
      
#         dict_list = []
#         answer = 0
        
#         for i in range(len(items)):
#             for j in range(len(items[0])):
#                 dict = {}
#                 dict["type"] = items[i][0]
#                 dict["color"] = items[i][1]
#                 dict["name"] = items[i][2]
#             dict_list.append(dict)

#         for i in range(len(dict_list)):
#             if dict_list[i][ruleKey] == ruleValue:
#                 answer += 1
        
#         return answer
