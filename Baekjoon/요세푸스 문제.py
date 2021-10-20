N, K = map(int, input().split())
answer = []
people = [i for i in range(1, N + 1)]
idx = 0

while people:
    idx += K - 1
    if idx >= len(people):
        idx %= len(people)
    
    answer.append(people.pop(idx))

print("<", ', '.join([str(i) for i in answer]), ">", sep="")
