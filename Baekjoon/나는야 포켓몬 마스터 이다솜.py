import sys

N, M = map(int, input().split())
name_dict, num_dict = {}, {}
problems = []
for i in range(N):
    monster_name = sys.stdin.readline().rstrip()
    name_dict[monster_name] = i + 1
    num_dict[str(i + 1)] = monster_name

for i in range(M):
    problems.append(sys.stdin.readline().rstrip())

for problem in problems:
    if problem in name_dict.keys():
        print(name_dict[problem])
    
    if problem in num_dict.keys():
        print(num_dict[problem])
