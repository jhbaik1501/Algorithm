num = int(input())
input_arr = map(int, input().split())
index = 0
arr = []
for i in input_arr:
    if len(arr) == 0:
        index += 1
        arr[0] = input_arr
    elif not i in arr:
