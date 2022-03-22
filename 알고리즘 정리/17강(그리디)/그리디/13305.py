num =int(input())
distance = list(map(int,input().split()))
weight = list(map(int,input().split()))

k =0
add_dis = distance[0]
price = 0
for i in range(1, num):
    
    if (i == num-1):
        #add_dis += distance[i]
        print("w, d", weight[k], add_dis)
        price += weight[k] * add_dis
        break

    if weight[k] < weight[i] :
        add_dis += distance[i]
        continue
    else :
        price += weight[k] * add_dis
        add_dis = distance[i]
        k= i
        print("price:" ,price)

print(price)
        


'''
4 
2 3 1 
5 2 4 1
18

4
2 3 1
5 7 4 1
29
'''