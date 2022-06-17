import sys

N = int(input())
book_dict = {}

for _ in range(N):
    title = sys.stdin.readline().rstrip()
    try:
        book_dict[title] += 1
    except KeyError:
        book_dict[title] = 1

book_info = []
for key, val in book_dict.items():
    book_info.append((key, val))

book_info.sort(key=lambda x: (-x[1], x[0]))
print(book_info[0][0])
