
number_list = list(range(0,100))
print(number_list)
sum_1 = 0
sum_2 = 0
for item in number_list:
    if item % 3 == 0:
        sum_1 = item + sum_1
    elif item % 10 == 0:
        sum_2 = item + sum_2
    totalt = sum_1 +sum_2
print(totalt)


for i in range(0,len(number_list),2):
        number_list[i] = i+1
        number_list[i+1] = i
print(number_list)

reversed_list = []
for i in range(len(number_list)-1,-1,-1):
    tall = number_list[i]
    reversed_list.append(tall)
print(reversed_list)

