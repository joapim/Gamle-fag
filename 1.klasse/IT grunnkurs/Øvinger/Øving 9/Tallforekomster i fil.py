#a
def numbers_of_lines(filename):
    antall_linjer = 0
    with open(filename,'r') as file:
        for i in range(0, len(file.readlines())):
            antall_linjer +=1
    return antall_linjer

print(numbers_of_lines('numbers.txt'))

#b
def numbers_frequency(filename):
    with open(filename) as file:
        liste = []
        frekvens = {}
        for line in file.readlines():
            liste.append(line[0])
        for i in range(0,len(liste)):
            if liste[i] not in frekvens:
                frekvens[liste[i]] = 1
            else:
                frekvens[liste[i]] +=1
        for key in frekvens.keys():
            a = print(key,': ',frekvens[key], sep=(''))
    return a

print(numbers_frequency('numbers.txt'))


