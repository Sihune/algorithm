def solution(n, l, r):
    def count_bit_1(num):
        if num <= 5: return '11011'[:num].count('1')

        base = 1
        while 5 ** (base + 1) < num:
            base += 1

        print(base)
        section = num // (5 ** base)
        remainder = num % (5 ** base)
        print(section, remainder)

        answer = section * (4 ** base)

        if section >= 3:
            answer -= (4 ** base)

        if section == 2:
            return answer
        else:
            return answer + count_bit_1(remainder)

    return count_bit_1(r) - count_bit_1(l - 1)

n=2
l=4
r=17

print(solution(n,l,r))