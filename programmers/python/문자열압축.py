
class solve:
    def my_solution(self, s):
        answer = len(s)

        for i in range(1, len(s) // 2+1):
            curIdx = i * 2
            prevIdx = i
            prevStr = s[0:i]
            cnt = 1
            comStr = ''
            while curIdx <= len(s):
                if prevStr != s[prevIdx:curIdx]:
                    comStr += (str(cnt) if cnt > 1 else '') + prevStr
                    prevStr = s[prevIdx:curIdx]
                    cnt = 1
                else:
                    cnt += 1
                if curIdx == len(s):
                    comStr += (str(cnt) if cnt > 1 else '') + prevStr
                    break
                prevIdx = curIdx
                curIdx = len(s) if curIdx+i > len(s) else curIdx+i

            answer = min(answer, len(comStr))

        return answer

    def compress(self, text, tok_len):
        words = [text[i:i + tok_len] for i in range(0, len(text), tok_len)]
        res = []
        cur_word = words[0]
        cur_cnt = 1
        for a, b in zip(words, words[1:] + ['']):
            if a == b:
                cur_cnt += 1
            else:
                res.append([cur_word, cur_cnt])
                cur_word = b
                cur_cnt = 1
        return sum(len(word) + (len(str(cnt)) if cnt > 1 else 0) for word, cnt in res)

    def solution(self, text):
        return min(self.compress(text, tok_len) for tok_len in list(range(1, int(len(text) / 2) + 1)) + [len(text)])


# print(solution("abcabcabcabcdededededede"))
# print(solution("a"))