def solution(seat):
    seat_dict = {}
    answer = 0

    for pos in seat:
        if tuple(pos) in seat_dict.keys():
            continue

        seat_dict[tuple(pos)] = 1
        answer += 1

    return answer
