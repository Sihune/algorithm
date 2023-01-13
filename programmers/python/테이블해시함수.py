def solution(data, col, row_begin, row_end):
    answer = 0
    sorted_data = sorted(data, key=lambda x: (x[col-1], -x[0]))
    print(sorted_data)
    for t in range(row_begin-1, row_end):
        mod = 0
        tuples = sorted_data[t]
        for tuple in tuples:
            mod += tuple % (t+1)
            print(mod)
        answer ^= mod
    return answer

data = [[2,2,6],[1,5,10],[4,2,9],[3,8,3]]
col = 2
row_begin = 2
row_end = 3

print(solution(data, col, row_begin, row_end))