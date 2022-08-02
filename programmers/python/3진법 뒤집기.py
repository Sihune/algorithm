def my_solution(n):
    three = ''
    while n > 0:
        three += str(n % 3)
        n //= 3
    return int(three, 3)

print(my_solution(45))