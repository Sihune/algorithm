from collections import deque

def solution(n, edge):
    answer = 0
    graph = {}
    visited = [[0 for _ in range(2)] for _ in range(n+1)]
    for u, v in edge:
        if u in graph:
            graph[u].append(v)
        else:
            graph[u] = [v]

        if v in graph:
            graph[v].append(u)
        else:
            graph[v] = [u]

    maxN = 0
    q = deque()
    q.append(1)
    visited[1][0] = 1
    while len(q) > 0:
        node = q.popleft()
        for e in graph[node]:
            print(e, visited[e][0])
            if visited[e][0] == 0:
                visited[e][0] = 1
                visited[e][1] = visited[node][1] + 1
                maxN = max(maxN, visited[e][1])
                q.append(e)

    for i, (_, cnt) in enumerate(visited):
        if cnt == maxN:
            answer += 1

    return answer



print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))