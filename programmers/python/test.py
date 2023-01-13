# def test(list):
#     list[0] = 5
#     print("hello")
#
# list = [1,2,3,4]
# test(list)
#
# print("pop: " + str(list.pop(0)))
# print(list)

# a = 1234
#
# a = [0] + list(map(int, list(str((a)))))
# print(a)

data = [[2,2,6],[1,5,10],[4,2,9],[3,8,3]]

sorted_data = sorted(data, key=lambda x: (x[1], x[0]))
print(sorted_data)
