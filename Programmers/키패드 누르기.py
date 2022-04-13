def solution(numbers, hand):
    answer = ''
    pos_dict = {'1': (0, 0), '2': (0, 1), '3': (0, 2),
                '4': (1, 0), '5': (1, 1), '6': (1, 2),
                '7': (2, 0), '8': (2, 1), '9': (2, 2),
                '0': (3, 1)}
    
    l_y, l_x = (3, 0)
    r_y, r_x = (3, 2)
    for number in numbers:
        if number in (1, 4, 7):
            answer += 'L'
            l_y, l_x = pos_dict[str(number)]
            
        elif number in (3, 6, 9):
            answer += 'R'
            r_y, r_x = pos_dict[str(number)]
            
        else:
            pos_y, pos_x = pos_dict[str(number)]
            dist_l = abs(l_y - pos_y) + abs(l_x - pos_x)
            dist_r = abs(r_y - pos_y) + abs(r_x - pos_x)
            
            if dist_l > dist_r:
                answer += 'R'
                r_y, r_x = pos_y, pos_x
                
            elif dist_l < dist_r:
                answer += 'L'
                l_y, l_x = pos_y, pos_x
                
            else:
                if hand == "right":
                    answer += 'R'
                    r_y, r_x = pos_y, pos_x
                    
                else:
                    answer += 'L'
                    l_y, l_x = pos_y, pos_x
                  
    return answer
