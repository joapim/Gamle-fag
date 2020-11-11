#a
import random
def randList(size, lower_bound, upper_bpund):
    liste = []
    for i in range(0, size):
        tall = random.randint(lower_bound, upper_bpund)
        liste.append(tall)
    return liste
print(randList(10,1,10))
#b
def compareLists(list1, list2):
    return [x for x in list1 if x in list2]
#c - ikke gjort

#def multiCompList(lists):
#
def longestEven(list): #fikk bare til antall partall
    antall = 0
    liste = []
    for i in range(0, len(list)):
        if list[i] % 2 == 0:
            liste.append(list[i])
    for element in list:
        if element % 2 == 0:
            antall += 1
    return liste,antall
print(longestEven([1,2,3,4,4,9,]))
