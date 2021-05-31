class Solution:
    def minPartitions(self, n: str) -> int:
        max_num = '0'
        for i in range(len(n)):
            if n[i] > max_num:
                max_num = n[i]

        return int(max_num)
