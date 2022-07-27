class solve:

    def my_solution(self, id_list, report, k):
        answer = {}

        check_list = {}
        acc_list = {}
        visited = {}
        for x in id_list:
            answer[x] = 0

        for x in report:
            if x not in visited:
                visited[x] = 1
                src, dst = x.split(" ")
                if dst not in check_list:
                    check_list[dst] = 1
                else:
                    check_list[dst] += 1

                if src in acc_list:
                    acc_list[src].append(dst)
                else:
                    acc_list[src] = [dst]

        stop_list = []
        for key in check_list:
            if check_list[key] >= k:
                stop_list.append(key)

        for key in acc_list:
            cnt = 0
            cur = acc_list[key]
            for stop in stop_list:
                if stop in cur:
                    cnt += 1
            answer[key] = cnt

        return list(answer.values())

    def solution(self, id_list, report, k):
        answer = [0] * len(id_list)
        acc_list = {x : 0 for x in id_list}

        for rep in set(report):
            acc_list[rep.split(" ")[1]] += 1

        for rep in set(report):
            if acc_list[rep.split(" ")[1]] >= k:
                answer[id_list.index(rep.split()[0])] += 1

        return answer


print(solve().solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))

# print(solution(["con", "ryan"], ["ryan con", "ryan con", "ryan con", "ryan con"], 3))