N = int(input())
liquid_list = list(map(int, input().split()))
liquid_list.sort()

if liquid_list[0] >= 0: 
    print(liquid_list[0], liquid_list[1])
    
elif liquid_list[-1] <= 0: 
    print(liquid_list[-2], liquid_list[-1])
    
else:
    max = 1e+9
    start, end = 0, N - 1
    while start < end:
        result = liquid_list[start] + liquid_list[end]
        
        if abs(result) < max: 
            max = abs(result)
            answer = [liquid_list[start], liquid_list[end]]

            if max == 0: 
                break
        
        if result > 0: 
            end -= 1
            
        else:
            start += 1
        
    print(answer[0], answer[1])
