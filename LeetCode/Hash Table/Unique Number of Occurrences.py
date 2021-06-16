class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        lookup = {}
        num_set = set()
        for num in arr:
            if num in lookup:
                lookup[num] += 1
            else:
                lookup[num] = 1
        
        for value in lookup.values():
            num_set.add(value)

        return True if len(lookup) == len(num_set) else False
