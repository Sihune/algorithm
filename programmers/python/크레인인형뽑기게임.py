def solution(board, moves):
    answer = 0

    bucket = [-1]
    for move in moves:

        for idx, i in enumerate([line[move-1] for line in board]):
            if i != 0:
                if bucket[len(bucket)-1] == i:
                    answer += 2
                    bucket.pop()
                else :
                    bucket.append(i)

                board[idx][move-1] = 0
                break
                
    return answer

print(solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]],
[1,5,3,5,1,2,1,4]))


