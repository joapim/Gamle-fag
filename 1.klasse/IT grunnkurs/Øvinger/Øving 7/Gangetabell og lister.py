#a
def seperate(numbers,threshold):
    liste_1 = []
    liste_2 = []
    for item in numbers:
        if item < threshold:
            liste_1.append(item)
        else:
            liste_2.append(item)
    return liste_1,liste_2
print(seperate([2,4,5,2,3,54,2,54,7634],7))

#b
import pprint
def multiplcation_table(n):
    m = list(list(range(1 * i, (n + 1) * i, i)) for i in range(1, n + 1))
    for i in m:
        i = [str(j).rjust(len(str(m[-1][-1])) + 1) for j in i]
        print(''.join(i))
print(multiplcation_table(10))