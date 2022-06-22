def count_num(n, d):
    count, div = 0, d
    while n >= div:
        count += n // div
        div *= d
        
    return count


n, m = map(int, input().split())
answer = 0

two_cnt = count_num(n, 2) - count_num(n - m, 2) - count_num(m, 2)
five_cnt = count_num(n, 5) - count_num(n - m, 5) - count_num(m, 5)
print(min(two_cnt, five_cnt))
    
