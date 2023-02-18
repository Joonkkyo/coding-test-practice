N = int(input())
ranks = list(map(int, input().split()))

rank_dict = {}
for i in range(N):
    rank_dict[ranks[i]] = ranks[i] - (i + 1)

sorted_dict = sorted(rank_dict.items())
for key, val in sorted_dict:
    print(val)
