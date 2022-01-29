num_list = set(range(1, 10001))
gen_list = set()

for i in range(1, 10001):
    for j in str(i):
        i += int(j) 
    gen_list.add(i)

answer = sorted(num_list - gen_list)

for num in answer:
    print(num)
