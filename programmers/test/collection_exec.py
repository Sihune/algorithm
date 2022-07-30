from collections import deque


def BFS_with_adj_list(graph, root):
    visited = []
    queue = deque([root])

    while queue:
        n = queue.popleft()
        if n not in visited:
            visited.append(n)
            queue += graph[n] - set(visited)
    return visited


graph_list = {1: {3, 4},
              2: {3, 4, 5},
              3: {1, 5},
              4: {1},
              5: {2, 6},
              6: {3, 5}}
root_node = 1

print(BFS_with_adj_list(graph_list, root_node))
