N = int(input())
loads = list(map(int, input().split()))
prices = list(map(int, input().split()))

answer = 0
min_price = prices[0]

for i in range(len(loads)):
    if prices[i] < min_price:
        min_price = prices[i]
        
    answer += min_price * loads[i]

print(answer)
