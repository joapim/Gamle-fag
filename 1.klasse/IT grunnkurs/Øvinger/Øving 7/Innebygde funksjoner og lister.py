#a
import random
random_numbers = []
for i in range(0,10):
    tall = random.randint(1,10)
    random_numbers.append(tall)
print(random_numbers)

#b
def finn_tall(tall):
    antall = 0
    for element in random_numbers:
        if tall == element:
            antall += 1
    return antall
finn_tall(2)
#c
print(sum(random_numbers))
#d
random_numbers.sort()
print(random_numbers)
#e skjønte ikke
#f
random_numbers.reverse()
print(random_numbers)


