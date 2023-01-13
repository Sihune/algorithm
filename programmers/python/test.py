# def test(list):
#     list[0] = 5
#     print("hello")
#
# list = [1,2,3,4]
# test(list)
#
# print("pop: " + str(list.pop(0)))
# print(list)

a = 1234

a = [0] + list(map(int, list(str((a)))))
print(a)