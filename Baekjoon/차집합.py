N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
A, B = set(A), set(B)
print(len(A - B))
print(*sorted(list(A - B)))

