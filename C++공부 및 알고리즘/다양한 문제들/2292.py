N = int(input())
i= 1
index =0
while True:
    i += 6*index
    index += 1
    if N <= i:
        print(index)
        break
