def draw_star(n):
    if n == 1:
        return ['*']
    n //= 3
    star = draw_star(n)
    print(star)
    top_bottom = [i * 3 for i in star]
    middle = [i + ' ' * n + i for i in star]
    return top_bottom + middle + top_bottom

N = int(input())
answer = '\n'.join(draw_star(N))
print(answer)
