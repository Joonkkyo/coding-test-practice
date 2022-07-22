import sys

emp_dict, emp_arr = {}, []
n = int(input())

for _ in range(n):
    name, action = sys.stdin.readline().split()
    if name in emp_dict:
        if action == 'enter':
            emp_dict[name] = True
        else:
            emp_dict[name] = False
    else:
        emp_dict[name] = True

for key in emp_dict.keys():
    if emp_dict[key]:
        emp_arr.append(key)

emp_arr.sort(reverse=True)
for emp in emp_arr:
    print(emp)
