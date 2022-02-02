N = int(input())
string = '666'
movie_num = 666

while N:
    if string in str(movie_num):
        N -= 1
    movie_num += 1
    
print(movie_num - 1)    
