class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        pos = k - 1
        friends = [i + 1 for i in range(n)]
        
        while True:
            if len(friends) == 1:
                return friends[0]
              
            del friends[pos]
            pos = (pos + k - 1) % len(friends)
