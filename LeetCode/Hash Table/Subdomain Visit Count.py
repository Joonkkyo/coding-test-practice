class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        domainMap = {}
        answer = []
        
        for domain in cpdomains:
            count = domain.split(' ')[0]
            domain = domain.split(' ')[1]
            domain_list = domain.split('.')
            
            for i in range(len(domain_list)):
                key_list = domain_list[i:]
                key = '.'.join(key_list)
                
                if key in domainMap:
                    domainMap[key] += int(count)
                else:
                    domainMap[key] = int(count)
                    
        for key, value in domainMap.items():
            answer.append(str(value) + ' ' + key)
            
        return answer
            
            
                                     

